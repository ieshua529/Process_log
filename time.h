/*
 * Пока не определились с ф-цией открытия файла
 * "openfile.h"  не создавал и оставил в комментах
 */

#ifndef TIME_H
#define TIME_H

// #include "openfile.h"

class TIME{
private:
	int hour;
	int minutes;

public:
	//friend FILE * OpenFile();
	// @TODO: как именно будем задавать значения.. в SET_TIME'e ??

	TIME();

	// Хз можно ли вызывать friend-function в методе
	void SET_TIME( );


};

#endif

