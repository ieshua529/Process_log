
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

#include <windows.h>
#include <all_process.h>

#define tasklist  "TASKLIST /FI \"USERNAME NE NT AUTORITY\SYSTEM\" /FI \"STATUS eq running\" /FO CSV /NH > 1.txt"

/*
#include <iostream>
using namespace std;
*/







#endif



