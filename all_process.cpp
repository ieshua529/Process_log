
#include "all_process.h"

ALL_PROCESS::ALL_PROCESS() {

	if ( (p_list = fopen(_FILE_ALL_PROCESS, "r") ) ==  NULL){
		WriteToLog(">>> error: File process_list couldn't be create");
	}else {
		all_process.reserve(50);
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
			char name_of_process[40]="\0";
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
			Obj.SetProcesTimeAndDate( *currentTime ) ;
			Obj.SetProcesPID ( Pid );
			Obj.SetTime_t(t);
			V.push_back(Obj);
			k++;
		}
	V.pop_back();
	rewind(p_list); 
}

string Conversation (time_t t_finish, time_t t_begin){
//	time_t T = difftime(t_finish,t_begin);
	time_t T = t_finish - t_begin;
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


vector<PROCES> WriteChangesToLOG (vector<PROCES> &V1, vector<PROCES> &V2){
	PROCES O1 , O2;
	int Count = 0;
	string temp1, temp2;
	char txt[100]="\0";
	vector<PROCES>::iterator i,j;
	vector<PROCES> V;
	time_t t = time(NULL);
	tm *currentTime = localtime(&t);
	for (i = V1.begin(); i != V1.end(); i++) {
		for (j = V2.begin(); j != V2.end(); j++){
			O1 = *i;
			O2 = *j;
			temp1 = O1.ShowProcesName();
			temp2 = O2.ShowProcesName();
			if (temp1 == temp2 && O1.ShowProcesPID() == O2.ShowProcesPID()){
				V.push_back(O1);
				Count++;
			}

		}
		if (Count == 0){
			// а на секунды пофигу
			if (currentTime->tm_hour >= 10 && currentTime->tm_min >= 10 ){
				sprintf(txt,"\n - : %s : %d : %d : %s : %d:%d:%d => %s", O1.ShowProcesName() , O1.ShowProcesPID() , O1.ShowProcesMemory() , O1.ShowProcesDate(), currentTime->tm_hour , currentTime->tm_min , currentTime->tm_sec, Conversation(t,O1.ShowTime_t()).c_str());
			} else if (currentTime->tm_hour >= 10 && currentTime->tm_min < 10 ){
				sprintf(txt,"\n - : %s : %d : %d : %s : %d:0%d:%d => %s", O1.ShowProcesName() , O1.ShowProcesPID() , O1.ShowProcesMemory() , O1.ShowProcesDate(), currentTime->tm_hour , currentTime->tm_min , currentTime->tm_sec, Conversation(t,O1.ShowTime_t()).c_str());
			} else if (currentTime->tm_hour < 10 && currentTime->tm_min >= 10 ){
				sprintf(txt,"\n - : %s : %d : %d : %s : 0%d:%d:%d => %s", O1.ShowProcesName() , O1.ShowProcesPID() , O1.ShowProcesMemory() , O1.ShowProcesDate(), currentTime->tm_hour , currentTime->tm_min , currentTime->tm_sec, Conversation(t,O1.ShowTime_t()).c_str());
			} else if (currentTime->tm_hour < 10 && currentTime->tm_min < 10 ){
				sprintf(txt,"\n - : %s : %d : %d : %s : 0%d:0%d:%d => %s", O1.ShowProcesName() , O1.ShowProcesPID() , O1.ShowProcesMemory() , O1.ShowProcesDate(), currentTime->tm_hour , currentTime->tm_min , currentTime->tm_sec, Conversation(t,O1.ShowTime_t()).c_str());
			}
			WriteToLog(txt);
			for(int i=0; i<100; i++) txt[i]='\0';
		}
		Count=0;		
	}

	for (i = V2.begin(); i != V2.end(); i++) {
		for (j = V1.begin(); j != V1.end(); j++){
			O1 = *i;
			O2 = *j;
			temp1 = O1.ShowProcesName();
			temp2 = O2.ShowProcesName();
			if (temp1 == temp2  && O1.ShowProcesPID() == O2.ShowProcesPID()){
				Count++;
			}
		}
		if (Count == 0){
			sprintf(txt,"\n + : %s : %d : %d : %s : %s", O1.ShowProcesName() , O1.ShowProcesPID() , O1.ShowProcesMemory() , O1.ShowProcesDate(), O1.ShowProcesTime());
			WriteToLog(txt);
			V.push_back(O1);
			for(int i=0; i<100; i++) txt[i]='\0';
		}
		Count = 0;
	}

	return V;
}



void WriteToLog(const char * to_log) {

		FILE *log;
		if(( log = fopen(_FILE_TO_LOG, "a+")) == NULL) {
			exit(1);
		}else {
			fputs(to_log, log);
			fclose(log);
		}
}

ALL_PROCESS::~ALL_PROCESS(){
	// - all_process.clear();
	fclose(p_list);
}

FILE * ALL_PROCESS::Value_P_List(){
	return p_list;
}

void ALL_PROCESS::Set_Value_P_List(FILE & f){
	*p_list = f;
}

vector <PROCES> & ALL_PROCESS::GetVectorAllProcess(){
	return 	all_process;
}
