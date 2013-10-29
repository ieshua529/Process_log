

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
	//	TimeAndDate->tm_hour = TimeAndDate->tm_min = TimeAndDate->tm_sec  =
	//		TimeAndDate->tm_mday  = TimeAndDate->tm_mon = TimeAndDate->tm_year = 0;
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

void PROCES::SetProcesTimeAndDate(tm * temp){
	*(TimeAndDate) = *(temp);
	// оказалось нет:/
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
	sprintf(temp,"%d/%d/%d",TimeAndDate->tm_hour,TimeAndDate->tm_min,TimeAndDate->tm_sec);
	return 	temp;
}

char * PROCES::ShowProcesDate(){
	char * temp = new char [11];
	sprintf(temp,"%d.%d.%d",TimeAndDate->tm_mday,TimeAndDate->tm_mon,TimeAndDate->tm_year);
	return 	temp;
}

PROCES::~PROCES(){
	delete [] TimeAndDate;
}



