
#include "all_process.h"

ALL_PROCESS::ALL_PROCESS() {

	// первым делом зафиксируем время
//	currentTime.SET_TIME( );


	all_process = new PROCES;
	if(!all_process) {
		WriteToLog("error: Object couldn't be create");
	}

	if ( (p_list = fopen(_FILE_ALL_PROCESS, "r") ) ==  NULL){
		WriteToLog("error: File process_list couldn't be create");
	}else {
		//int num_of_obj = NumberOfLines(p_list);     // эт не надо уже
		vector<PROCES> all_proces;
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
			Obj.memory = memory_of_process;
			Obj.name = name_of_process;
			Obj.TimeAndDate = currentTime ; 
			Obj.PID = Pid;
			V.push_back(Obj);								      
			k++;
		}
		rewind(p_list);
}

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
	delete [] all_process;
	fclose(p_list);
}

PROCES * ALL_PROCESS::Value_All_Process(){

	return all_process;
}
FILE * ALL_PROCESS::Value_P_List(){

	return p_list;
}
