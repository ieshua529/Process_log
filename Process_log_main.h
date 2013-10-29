
/*
 *  сюда выносим побочные ф-ции
 *  - определение ОС
 *  - обращение к cmd для получения process_list
 *  - проверка на существование такого же процесса при запуске
 *  -
 *
 */


#ifndef PROCESS_LOG_MAIN_H
#define PROCESS_LOG_MAIN_H

#include "all_process.h"

#include <windows.h>
#include <iostream>
#include <io.h>
#include <time.h>
#include <unistd.h>
#include <locale.h>


using namespace std;

const char * tasklist = "TASKLIST /FI \"USERNAME NE NT AUTORITY\SYSTEM\" /FI \"STATUS eq running\" /FO CSV /NH > process_list";
const char * exist = "exist";

string GET_OS_NAME() {
	#if (defined __linux__)
		return "LINUX";
	#else
	#if (defined __WIN32__)
		return "WINDOWS";
	#endif
	#endif
}

#ifndef _FILE_TO_LOG
#define _FILE_TO_LOG "log"
#endif
#ifndef _FILE_ALL_PROCESS
#define _FILE_ALL_PROCESS "process_list"
#endif



void HideWindow(void);
void GetProcessList();
ALL_PROCESS Initialization(const bool);
void Timer(const int);
void CheckProcess(ALL_PROCESS );
bool FileExists(const char *);


#endif



