
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

		//заранее выделяю память для большего числа процессов..чтобы не было перекопирования вектора,
		// если вдруг не хватит памяти
		 all_process.reserve(30);

	}
}

ALL_PROCESS::ALL_PROCESS(int size){

	all_process.reserve( size );
	if ((p_list = fopen(_FILE_ALL_PROCESS, "r") ) ==  NULL){
		WriteToLog("error: File process_list couldn't be open");
	}
}

void  GetNameAndMemory (FILE *p_list , vector<PROCES> & V) {
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
	rewind(p_list); 
}

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

//			[operation] : [name] : [PID] : [memory] : [date] : [time] & [workTime]
void WriteChangesToLOG (vector <PROCES> &V1 , vector <PROCES> &V2){ // v1 главный вектор v2 только считанный
	PROCES O1 , O2;
	int Count = 0;
	char txt[100];
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
		if (Count == 0){
			//cout<<O1.ShowProcesName()<<" просуществовал "<<Conversation(t,O1.ShowTime_t())<<endl;
			sprintf(txt," - : %s : %d : %d : %s : %s & %s\n", O1.ShowProcesName() , O1.ShowProcesPID() , O1.ShowProcesMemory() , O1.ShowProcesDate(), O1.ShowProcesTime(), Conversation(t,O1.ShowTime_t()).c_str());
			WriteToLog(txt);
			for(int i=0; i<100; i++) txt[i]='\0';
		}
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
		if (Count == 0) {
			sprintf(txt," - : %s : %d : %d : %s : %s & %s\n", O2.ShowProcesName() , O2.ShowProcesPID() , O2.ShowProcesMemory() , O2.ShowProcesDate(), O2.ShowProcesTime(), Conversation(t,O2.ShowTime_t()).c_str());
			WriteToLog(txt);
			V.push_back(O2);
			for(int i=0; i<100; i++) txt[i]='\0';
		}
		Count = 0;
	}
	V1.clear();
	copy(V1.begin(),V.begin(),V.end());
}


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
	all_process.clear();
	fclose(p_list);
}

FILE * ALL_PROCESS::Value_P_List(){
	return p_list;
}

void ALL_PROCESS::Set_Value_P_List(FILE & f){
	*p_list = f;
}


vector <PROCES> & ALL_PROCESS::GetVectorAllProces(){
	return 	all_process;
}


/*void operator == (const ALL_PROCESS & ALL){


}*/
