/*
 * Класс хранящий информацию об отдельном процессе
 *
 */

#ifndef PROCES_H
#define PROCES_H

#include "time.h"
#include "date.h"

class PROCES {
private :
	char *name;// string
	TIME time;
	C_DATE date;

public :
	PROCES();
	// ...
	~PROCES();
};

#endif

