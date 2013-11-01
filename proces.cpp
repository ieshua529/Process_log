

#include "proces.h"


PROCES::PROCES(){

	name = "none";

	TimeAndDate = new struct tm;
	TimeAndDate->tm_hour = TimeAndDate->tm_isdst = TimeAndDate->tm_mday =
			TimeAndDate->tm_min = TimeAndDate->tm_mon = TimeAndDate->tm_sec =
					TimeAndDate->tm_wday = TimeAndDate->tm_yday = TimeAndDate->tm_year = 0;
	memory = 0;
	PID = 0;
	t = 0;
}

void PROCES::SetProcesMemory(int x){
	memory = x;
}

void PROCES::SetProcesPID(int x){
	PID = x;
}

void PROCES::SetProcesName(string newName){
	if(newName.length() > 0){
		name = newName;
	}else{
		// write to log error
	}
}

void PROCES::SetTime_t (time_t t1){
	t = t1;
}

void PROCES::SetProcesTimeAndDate(tm  temp){
	*TimeAndDate = temp;
}

const char * PROCES::ShowProcesName(){
	return name.c_str();
}

int PROCES::ShowProcesPID(){
	return PID;
}

int PROCES::ShowProcesMemory(){
	return memory;
}

char * PROCES::ShowProcesTime(){
	char * temp = new char [8];
	if(TimeAndDate->tm_hour < 10) {
		sprintf(temp,"0%d:%d:%d",TimeAndDate->tm_hour,TimeAndDate->tm_min,TimeAndDate->tm_sec);
	}else{
		sprintf(temp,"%d:%d:%d",TimeAndDate->tm_hour,TimeAndDate->tm_min,TimeAndDate->tm_sec);
	}
return 	temp;
}

char * PROCES::ShowProcesDate(){
	char * temp = new char [11];
	if(TimeAndDate->tm_mday < 10){
		sprintf(temp,"0%d.%d.%d",TimeAndDate->tm_mday , TimeAndDate->tm_mon + 1 ,TimeAndDate->tm_year + 1900);
	} else {
		sprintf(temp,"%d.%d.%d",TimeAndDate->tm_mday , TimeAndDate->tm_mon + 1 ,TimeAndDate->tm_year + 1900);
	}
	return 	temp;
}

PROCES::~PROCES(){
//	delete [] TimeAndDate;
}

time_t PROCES::ShowTime_t() {
		return t;
}


