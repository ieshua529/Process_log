/*
 * Класс хранящий информацию об отдельном процессе
 * и больше никаких ф-ций для него нет??0_о
 *
 */

#ifndef PROCES_H
#define PROCES_H

//#include "time.h"
//#include "date.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class PROCES {
private :
	string name;
	int memory;
	tm * TimeAndDate;

public :
	PROCES();
	// ...
	~PROCES();
friend void GetNameAndMemory (FILE *F , PROCES *Obj);
//	friend int  NumberOfLines 	 (FILE *F);

};

#endif

