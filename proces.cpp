/*
 *
 */

#include "proces.h"
#include <stdio.h>
#include <stdlib.h>

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
			Obj[k].memory = memory_of_process;    // тут надо как-то подругому инициализировать
			Obj[k].name = name_of_process;        // возможно передавать сюда сразу дату и время
			k++;                                  // и использовать конструктор ..
		}
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