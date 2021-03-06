/*
 * Класс хранящий информацию об отдельном процессе
 * и больше никаких ф-ций для него нет??0_о
 *
 */

#ifndef PROCES_H
#define PROCES_H

//#include "time.h"
//#include "date.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

class PROCES {
private :
	string name;
	int memory;
	tm * TimeAndDate;
	int PID;
	time_t t;

public :
	PROCES();
	// ...
	~PROCES();
	void SetProcesMemory(int);
	void SetProcesPID(int );
	void SetProcesName(string );
	void SetProcesTimeAndDate(tm );
	void SetTime_t(time_t);

	const char * ShowProcesName();
	char * ShowProcesDate();
	char * ShowProcesTime();
	int ShowProcesMemory();
	int ShowProcesPID();
	time_t ShowTime_t ();

friend void  GetNameAndMemory (FILE * , vector<PROCES> & );
friend vector <PROCES> WriteChangesToLOG (vector <PROCES> &V1 , vector <PROCES> &V2);
friend string Conversation (time_t , time_t);

};

#endif

