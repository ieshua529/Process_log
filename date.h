/*
 * Пока не определились с ф-цией открытия файла
 * "openfile.h"  не создавал и оставил в комментах
 */


#ifndef DATE_H
#define DATE_H

// #include "openfile.h"

class C_DATE {
private:
	int day;
	int month;
	int year;

public:
	C_DATE();

	// опять же что с аргументами не ясно пока что
	void TO_SET();

};


#endif
