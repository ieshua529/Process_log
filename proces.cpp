/*
 *
 */

#include "proces.h"


PROCES::PROCES(){
	name = new char[5];
	strcpy(name, "none\0");
	C_DATE date;  
	TIME time;
	
}

PROCES::PROCES(const char *n, TIME t,  C_DATE d){

	name = new char[sizeof(n)/sizeof(char)];
	strcpy(name, n);
	TIME time(t);
	C_DATE date(d);

}



PROCES::~PROCES(){

}


void  GetNameAndMemory (FILE *p_list , PROCES *Obj) {        // парсер
	char s1[100];
	int counter_quotes=0, length_of_line, j, memory_of_process, k=0;
	time_t t = time(NULL);						// или закинуть в функциюю считывания тасклиста в файл
	tm *currentTime = localtime(&t);            // пусть там сразу определяет время и сюда передавать через параметры
												// разница по времени будет не значитела
	    while (!feof(p_list)){
			fgets(s1,100,p_list);
			length_of_line=strlen(s1);
			counter_quotes=0;
			char name_of_process[20]="\0";
			char mem[10]="\0";
			for (int i = 0;i < length_of_line; i++) {
				if (s1[i] == '"') {
					counter_quotes++;
					i++;
					if (counter_quotes == 1) {
						j=0;
						while (s1[i]!= '"') {
							name_of_process[j]=s1[i];
							j++;
							i++;
						}
						counter_quotes++;
					}

					if (counter_quotes == 9) {
						j=0;
						while (s1[i]!= '"') {
							if (s1[i] >= '0' && s1[i] <= '9') {
								mem[j]=s1[i];
								j++;	
							}
							i++;
						}
						counter_quotes++;
					}
				}
			}
			memory_of_process = atoi (mem);
			Obj[k].memory = memory_of_process;    
			Obj[k].name = name_of_process;
			Obj[k].TimeAndDate = currentTime;     // так будет лучше всего хранить, не надо 2  класса сразу
		     								      // да и много чего другого
			k++;                                  
		}
		rewind(p_list);
}


int NumberOfLines (FILE *p_list) {       //Считает количество строк в файле
	int Count = 0;
	char str[100];
	while (!feof(p_list)) {
		fgets(str, 100, p_list);
		Count++;
	}
	rewind(p_list);
	return Count;
}