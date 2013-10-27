

#ifndef ALL_PROCESS_H
#define ALL_PROCESS_H

#include "proces.h"
#include <vector>
#include <stdio.h> // for FILE
#include <time.h>


// #include "openfile.h"

// пути до файлов:
// 1. без расширения - оно нам и не надо
// 2. пока работаем в текущей директории
#ifndef _FILE_TO_LOG
#define _FILE_TO_LOG "log"
#endif
#ifndef _FILE_ALL_PROCESS
#define _FILE_ALL_PROCESS "process_list"
#endif

class ALL_PROCESS {
private:

	PROCES *all_process;
	FILE *p_list;

	//FILE *log;
	// текущее время

//	TIME currentTime;


public:

	ALL_PROCESS();
	PROCES * Value_All_Process();
	FILE * Value_P_List();

	// так как работа с файлом организуется через френд-функ openfile()
	friend void GetNameAndMemory (FILE *F , vector<PROCES> V);

	~ALL_PROCESS();

};

void WriteToLog(const char *);

#endif
