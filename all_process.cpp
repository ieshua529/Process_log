
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
		vector <PROCES> all_proces;
	}
}

ALL_PROCESS::ALL_PROCESS(int size){
	PROCES temp;
	all_process.resize(size, temp );
	if ((p_list = fopen(_FILE_ALL_PROCESS, "r") ) ==  NULL){
		WriteToLog("error: File process_list couldn't be open");
	}
}


void  GetNameAndMemory (FILE *p_list , vector<PROCES> V) {
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
			Obj.SetProcesMemory(memory_of_process ); // похоже что тут всё равно косяк был...глянь чуть ниже как ты получил доступ
			Obj.SetProcesName ( name_of_process) ; // к закрытым элементам 0_о
			Obj.SetProcesTimeAndDate(currentTime ) ;
			Obj.SetProcesPID ( Pid );
			Obj.SetTime_t(t);
			V.push_back(Obj);


			k++;
		}
		rewind(p_list);
}

//vector<PROCES> Compare (vector<PROCES> &V1, vector<PROCES> &V2){
//	PROCES O1 , O2;
//	int Count = 0;
//	vector<PROCES>::iterator i,j;
//	vector<PROCES> V;
//	for (i = V1.begin(); i != V1.end(); i++) {
//		for (j = V2.begin(); j != V2.end(); j++){
//			O1 = *i;
//			O2 = *j;
//			if (O1.name == O2.name && O1.PID == O2.PID){
//				V.push_back(O1);
//				Count++;
//			}
//
//		}
//		if (Count == 0)
//			cout<<O1.name<<" просуществовал "<<difftime(O2.t,O1.t)<<" секунд"<<endl;
//		Count=0;
//	}
//
//	for (i = V2.begin(); i != V2.end(); i++) {
//		for (j = V1.begin(); j != V1.end(); j++){
//			O1 = *i;
//			O2 = *j;
//			if (O1.name == O2.name && O1.PID == O2.PID){
//				Count++;
//			}
//		}
//		if (Count == 0)
//			V.push_back(O1);
//		Count = 0;
//	}
//
//	return V;
//}

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


void GetNameAndMemory (FILE *p_list , PROCES *Obj) {
        char s1[100];
        int counter_quotes=0, length_of_line, j, memory_of_process, k=0;
        time_t t = time(NULL);                                                // или закинуть в функциюю считывания тасклиста в файл
        tm *currentTime = localtime(&t); // пусть там сразу определяет время и сюда передавать через параметры
                                                                                                // разница по времени будет не значитела
         while (!feof(p_list)){
                        fgets(s1,100,p_list);
                        length_of_line=strlen(s1);
                        counter_quotes=0;
                        char name_of_process[20]="\0";
                        char mem[10]="\0";
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
                        Obj[k].memory = memory_of_process;
                        Obj[k].name = name_of_process;
                        Obj[k].TimeAndDate = currentTime ; // так будет лучше всего хранить, не надо 2 класса сразу
                                                                                  // да и много чего другого
                        k++;
                }
                rewind(p_list);
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

	if(size_main >= size_temp){
		ALL_PROCESS TEMP_MAIN(size_main);
	}else {
		ALL_PROCESS TEMP_MAIN(size_temp);
	}

}
vector <PROCES> ALL_PROCESS::GetVectorAllProces(){
	return 	all_process;
}


/*void operator == (const ALL_PROCESS & ALL){


}*/
