

#include "proces.h"


PROCES::PROCES(){

	name = "none";
	TimeAndDate = NULL;
	memory = 0;
	PID = 0;

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

void PROCES::SetProcesTimeAndDate(const tm * temp){
	TimeAndDate->tm_hour 	= 	temp->tm_hour;
	TimeAndDate->tm_mday	= 	temp->tm_mday;
	TimeAndDate->tm_min 	= 	temp->tm_min;
	TimeAndDate->tm_mon 	= 	temp->tm_mon;
	TimeAndDate->tm_year 	=	temp->tm_year;
	TimeAndDate->tm_sec 	= 	temp->tm_sec;
// вот даже интересно верно ли то что я решил явно их поназначать?
}

PROCES::~PROCES(){
	delete [] TimeAndDate;
}



