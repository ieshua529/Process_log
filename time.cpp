
#include "time.h"

TIME::TIME(){
	//
	hour = 0;
	minutes = 0;

}

TIME::TIME(TIME &T){
	hour = T.hour;
	minutes = T.minutes;
}


void TIME::SET_TIME(){
	//

}

/*
 *  struct tm{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
	};
 */

/*
 *	  time_t t;
	  tm *tk;

	  time(&t);
	  tk=localtime(&t);

	  cout << 1900+tk->tm_year << 1+tk->tm_mon << tk->tm_mday << endl;
 */
