

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

	vector <PROCES> all_process;
	FILE * p_list;


public:

	ALL_PROCESS();
	ALL_PROCESS(int);
	PROCES * Value_All_Process();
	FILE * Value_P_List();
	void Set_Value_P_List( FILE & );


	~ALL_PROCESS();

	vector <PROCES> & GetVectorAllProces();

	void operator == (const ALL_PROCESS &);

	friend void WriteChangesToLOG (vector<PROCES> &,vector<PROCES>&);
	friend string Conversation (time_t , time_t);


};

int  NumberOfLines 	 (FILE *F);
void WriteToLog(const char *);

#endif
