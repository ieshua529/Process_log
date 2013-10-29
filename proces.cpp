

#include "proces.h"


PROCES::PROCES(){

	name = "none";
	TimeAndDate = NULL;
	memory = 0;
	pid = 0;

	//	TimeAndDate->tm_hour = TimeAndDate->tm_min = TimeAndDate->tm_sec  =
	//		TimeAndDate->tm_mday  = TimeAndDate->tm_mon = TimeAndDate->tm_year = 0;
}



PROCES::~PROCES(){
	delete [] TimeAndDate;
}



