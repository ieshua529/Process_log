/*
 * Класс хранящий информацию об отдельном процессе
 *
 */

#ifndef PROCES_H
#define PROCES_H

#include "time.h"
#include "date.h"
#include <stdio.h>
#include <string.h>

class PROCES {
private :
	char *name;// string  думаю лучше стринг сделать
	TIME time;    
	C_DATE date;    
	int memory;

public :
	PROCES();
	PROCES(const char *, TIME , C_DATE);
	// ...
	~PROCES();
	friend void GetNameAndMemory (FILE *F , PROCES *Obj);
	friend int NumberOfLines (FILE *F);
};

#endif

