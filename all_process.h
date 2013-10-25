

#ifndef ALL_PROCESS_H
#define ALL_PROCESS_H

#include "proces.h"

#include <stdio.h> // for FILE

// #include "openfile.h"

// пути до файлов:
// 1. без расширения - оно нам и не надо
// 2. пока работаем в текущей директории
#define _FILE_TO_LOG "log"
#define _FILE_ALL_PROCESS "process_list"


class ALL_PROCESS {
private:
	 // делаем динамически так как размер меняется и неопределён
	PROCES *all_process;

	// файл для записи туда log ... открываем в режиме - "a"
	FILE *log;

	//файл для считывания и распарсивания его
	FILE *p_list;

	// текущее время
	TIME currentTime;


public:
	// аргументы по ходу дела определим

	ALL_PROCESS();

	// собственно заготовка парсера
	// более чем уверен что выйдет ф-ции 3 но вне класса...
	// так как работа с файлом организуется через френд-функ openfile()
	void Parser();

	bool WriteToLog();

	// void InitProcessList () - что-то типа конструктора... посмотрим как будет проще

	~ALL_PROCESS();

};

#endif
