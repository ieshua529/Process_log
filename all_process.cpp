
#include "all_process.h"

ALL_PROCESS::ALL_PROCESS() {

	// первым делом зафиксируем время
//	currentTime.SET_TIME( );

	/*
	all_process = new PROCES;
	if(!all_process) {
		WriteToLog("error: Object couldn't be create");
	}
	*/

	if ( (p_list = fopen(_FILE_ALL_PROCESS, "r") ) ==  NULL){
		WriteToLog("error: File process_list couldn't be create");
	}else {
		//int num_of_obj = NumberOfLines(p_list);
		//all_process = new PROCES [ num_of_obj ];

		//@TODO: баг тута..не знаю.. но у меня как не смотрю не вызывается здесь конструктор для эл-та PROCES
		 all_process.reserve(20);

	}
}

ALL_PROCESS::ALL_PROCESS(int size){

	all_process.reserve( size );
	if ((p_list = fopen(_FILE_ALL_PROCESS, "r") ) ==  NULL){
		WriteToLog("error: File process_list couldn't be open");
	}
}

//@TODO: сюда надо передать по ссылке..!!!
void  GetNameAndMemory (FILE *p_list , vector<PROCES>  &V) {
	char s1[100];
	int counter_quotes=0, length_of_line, j, memory_of_process, k=0, Pid;
	time_t t = time(NULL);
	tm *currentTime = localtime(&t);
	PROCES Obj;

	    while (!feof(p_list)){
			fgets(s1,100,p_list);
			length_of_line=strlen(s1);
			counter_quotes=0;
			char name_of_process[20]="\0";
			char mem[10]="\0";
			char pid[10] = "\0";
			for (int i = 0;i < length_of_line; i++) {
				if (s1[i] == '"') {
					counter_quotes++;
					i++;
					if (counter_quotes == 1) {
						j=0;
						while (s1[i]!= '"') {
							name_of_process[j]=s1[i];
							j++;
							i++;
						}
						counter_quotes++;
					}
				if (counter_quotes == 3) {
					j=0;
					while (s1[i]!= '"') {
						pid[j]=s1[i];
						j++;
						i++;
					}
					counter_quotes++;
				}

					if (counter_quotes == 9) {
						j=0;
						while (s1[i]!= '"') {
							if (s1[i] >= '0' && s1[i] <= '9') {
								mem[j]=s1[i];
								j++;
							}
							i++;
						}
						counter_quotes++;
					}
				}
			}
			memory_of_process = atoi (mem);
			Pid = atoi(pid);
			Obj.SetProcesMemory(memory_of_process );
			Obj.SetProcesName ( name_of_process) ;
			Obj.SetProcesTimeAndDate(currentTime ) ;
			Obj.SetProcesPID ( Pid );
			Obj.SetTime_t(t);
			V.push_back(Obj);


			k++;
		}
	//	rewind(p_list);  // а зачем нам это? для возвращения указателя на начало файла
}

vector<PROCES> Compare (vector<PROCES> &V1, vector<PROCES> &V2){ // v1 главный вектор v2 только считанный
	PROCES O1 , O2;
	int Count = 0;
	vector<PROCES>::iterator i,j;
	vector<PROCES> V;
	time_t t = time(NULL);
	for (i = V1.begin(); i != V1.end(); i++) {
		for (j = V2.begin(); j != V2.end(); j++){
			O1 = *i;
			O2 = *j;
			if (O1.ShowProcesName() == O2.ShowProcesName() && O1.ShowProcesPID() == O2.ShowProcesPID()){
				V.push_back(O1);
				Count++;
			}

		}
		if (Count == 0)
			cout<<O1.ShowProcesName()<<" просуществовал "<<Conversation(t,O1.ShowTime_t())<<endl;
		Count=0;
	}

	for (i = V2.begin(); i != V2.end(); i++) {
		for (j = V1.begin(); j != V1.end(); j++){
			O1 = *i;
			O2 = *j;
			if (O1.ShowProcesName() == O2.ShowProcesName() && O1.ShowProcesPID() == O2.ShowProcesPID()){
				Count++;
			}
		}
		if (Count == 0)
			V.push_back(O1);
		Count = 0;
	}

	return V;
}

// оставлю эту ф-цию... на всякий вдруг что-то не сработает ... всё равно она перегружена

// как я вызывал весь этот шлак
//void main( )
//{
//	setlocale(0,"");
//	FILE *F, *F2;
//	str11 A, A2;
//	vector<PROCES> B,B2;
//	int c=0;
//	while (1){
//		if (c==0) {
//			F = fopen("1.txt","r");
//			GetNameAndMemory (F,B); 
//			c++;
//		}
//		else { 
//			F2 = fopen("2.txt","r");
//			GetNameAndMemory (F2,B2); 
//			B = Compare(B,B2);
//			Sleep(10000);
//			fclose(F2);
//			B2.clear();
//		}
//	}
//	getch();
//}

string Conversation (time_t t_finish, time_t t_begin){
	int T = difftime(t_finish,t_begin);
	int sec, min, days, hours;
	char str[40];
	sec = T%60;
	T =T/60;
	if (T!=0){
		min= T%60;
		T/=60;
		if (T != 0){
			hours = T%24;
			T/=24;
			if (T != 0){
				days = T;
				sprintf( str,"days: %d hours: %d min: %d sec: %d",days,hours,min,sec );
				return str;
			}
			else {
				sprintf( str,"hours: %d min: %d sec: %d",hours,min,sec );
				return str;
			}

		}
		else {
			sprintf( str,"min: %d sec: %d",min,sec );
			return str;
		}
	}
	else {
		sprintf( str,"sec: %d",sec );
		return str;
	}
}


int NumberOfLines (FILE *p_list) {       //Считает количество строк в файле
	int count = 0;
	char str[100];
	while (!feof(p_list)) {
		fgets(str, 100, p_list);
		count++;
	}
	rewind(p_list);
	return count;
}


// пока я так понимаю сам ещё не придумал куда вписать?
//for (vector<str11>::iterator i = B.begin(); i != B.end();i++){
//		A = *i;
//		cout<<A.name<<" "<<A.Memory<<" "<<A.TimeAndDate->tm_year<<endl;
//	}



void WriteToLog(const char * to_log) {

		FILE *log;
		if(( log = fopen(_FILE_TO_LOG, "a+")) == NULL) {
			exit(1);
		}else {
			fputs(to_log, log);
			fclose(log);
			exit(2);
		}
}

ALL_PROCESS::~ALL_PROCESS(){
	//delete [] all_process;
	all_process.clear();
	fclose(p_list);
}

//PROCES * ALL_PROCESS::Value_All_Process(){
//	return all_process;
//}
FILE * ALL_PROCESS::Value_P_List(){

	return p_list;
}

void WriteChangesToLOG( ALL_PROCESS & main , const  ALL_PROCESS & temp){
	int size_main = sizeof(main)/sizeof(ALL_PROCESS);
	int size_temp = sizeof(temp)/sizeof(ALL_PROCESS);

// @TODO: сравнить 2 вектора и записать в файл изменения

}

vector <PROCES>  ALL_PROCESS::GetVectorAllProces(){
	printf("%d",all_process.size());
	return 	all_process;
}


/*void operator == (const ALL_PROCESS & ALL){


}*/
