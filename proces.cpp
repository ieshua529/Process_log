/*
 *
 */

#include "proces.h"

#include <stdlib.h>

PROCES::PROCES(){
	name = new char[5];
	strcpy(name, "none\0");
	C_DATE date;
	TIME time;

}

PROCES::PROCES(const char *n, TIME t,  C_DATE d){

	name = new char[sizeof(n)/sizeof(char)];
	strcpy(name, n);
	TIME time(t);
	C_DATE date(d);

}



PROCES::~PROCES(){

}
