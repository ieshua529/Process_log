

#ifndef ALL_PROCESS_H
#define ALL_PROCESS_H

#include "proces.h"
#include <vector>
#include <stdio.h> // for FILE
#include <time.h>
#include <iostream>
using namespace std;


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
	FILE *p_list;


public:

	ALL_PROCESS();
	ALL_PROCESS(int);
	PROCES * Value_All_Process();
	FILE * Value_P_List();

	friend void  GetNameAndMemory (FILE *p_list , vector<PROCES>  &V);
	friend vector<PROCES> Compare (vector<PROCES> &V1, vector<PROCES> &V2);
	friend string Conversation (time_t t_finish, time_t t_begin);
	//friend void GetNameAndMemory (FILE *F , PROCES *);// странно но у меня не перегружается фрэнд функции

	~ALL_PROCESS();

	vector <PROCES>  GetVectorAllProces();

	void operator == (const ALL_PROCESS &);

	friend void WriteChangesToLOG( ALL_PROCESS &,const  ALL_PROCESS &);

};

int  NumberOfLines 	 (FILE *F);
void WriteToLog(const char *);

#endif
