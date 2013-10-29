

#ifndef ALL_PROCESS_H
#define ALL_PROCESS_H

#include "proces.h"
#include <vector>
#include <stdio.h> // for FILE
#include <time.h>



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

	PROCES *all_process; // что то не складывается... так то это вектор...>___<
	FILE *p_list;

	//FILE *log;
	// текущее время

//	TIME currentTime;


public:

	ALL_PROCESS();
	ALL_PROCESS(int);
	PROCES * Value_All_Process();
	FILE * Value_P_List();

	friend void GetNameAndMemory (FILE *F , vector<PROCES>);

	~ALL_PROCESS();

	void operator == (const ALL_PROCESS &);

	friend void WriteChangesToLOG( ALL_PROCESS &,const  ALL_PROCESS &);

};

int  NumberOfLines 	 (FILE *F);
void WriteToLog(const char *);

#endif
