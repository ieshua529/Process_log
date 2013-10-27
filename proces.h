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
public :         // с приватом надо сеттеры геттеры делать
	string name; // а так не прикольно >_<
	int memory;  // ну или переносить сюда GetNameAndMemory()
	tm * TimeAndDate;
	int PID;

	PROCES();
	// ...
	~PROCES();
friend void GetNameAndMemory (FILE *F , PROCES *Obj);
//	friend int  NumberOfLines 	 (FILE *F);

};

#endif

