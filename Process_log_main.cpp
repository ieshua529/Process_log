// некоторые команды
/*
 * TASKLIST /FI "USERNAME NE NT AUTORITY\SYSTEM" /FI "STATUS eq running" /FO CSV /NH > process_list
   TASKKILL /IM Process_log.exe

   $ date
   25 окт 2013 г.  1:17:29

 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "Process_log_main.h"


void GetProcessList() {

	if(GET_OS_NAME() == "WINDOWS"){

		system("chcp 1258");
		system(tasklist);

	} else if(GET_OS_NAME() == "LINUX"){
		// ...
	}

}


ALL_PROCESS Initialization(const bool is_exist){

	setlocale(0,"");

	// @TODO: первый раз пооткрываать файлы

	if(is_exist && FileExists(exist)) {
		remove(exist); // если включили с параметров '-e' то удаляем файл
	}

	// по теории если файл запускается без параметра или уже существует то выход
	if (FileExists(exist) || !is_exist){
		exit(0);
	}else{
		FILE *f;
		if ((f = fopen(exist, "w")) == NULL){
			exit(0);
		}
		fclose(f);
	}

	// отключу для видимости процесса
	//HideWindow();

	GetProcessList();

	// @TODO: не срабатывает конструктор как надо!!!
	ALL_PROCESS 	main_obj;

	GetNameAndMemory( main_obj.Value_P_List()  , main_obj.GetVectorAllProcess());


	main_obj.Set_Value_P_List(*(fopen(_FILE_TO_LOG , "a")));
	if( !(main_obj.Value_P_List())){
		WriteToLog(">>> Can't create _FILE_TO_LOG");
	}else{

/*
	При инициализации записываю в лог-файл первичное состояние процессов...
	а в CheckProcess()  идут их изменения
	новая сессия начинается со стоки из ###
	если процесс добавился его запись начинается с  => 			 + :
	исчез  =>			 - :

	пример:

		+ : explorer.exe : 1584 : 12345 : 01.02.2013 : 12-30

		[операция] : [name] : [PID] : [memory] : [date] : [time]

 */

		//@TODO: оформить в виде отдельной ф-ции
		fprintf(main_obj.Value_P_List(), " \n### :: %d :: %s :: %s",
				main_obj.GetVectorAllProcess().size() ,
				main_obj.GetVectorAllProcess().back().ShowProcesDate() ,
				main_obj.GetVectorAllProcess().back().ShowProcesTime());

		vector<PROCES>::iterator i;
		for(i = main_obj.GetVectorAllProcess().begin(); i != main_obj.GetVectorAllProcess().end() ; i++){

			fprintf( main_obj.Value_P_List(),"\n + : %s : %d : %d",
					i->ShowProcesName(),
					i->ShowProcesPID(),
					i->ShowProcesMemory() );
		}
		fputs("\n::",main_obj.Value_P_List());
		fclose( main_obj.Value_P_List());
	}

	return main_obj;
}

void Timer(const int time){
	if(GET_OS_NAME() == "WINDOWS"){
		Sleep(time);  // winAPI
	}else{
		USLEEP(time);
	}
}


void HideWindow(void){

	if(GET_OS_NAME() == "WINDOWS"){
		HWND hWnd = GetConsoleWindow();
		ShowWindow(hWnd, SW_HIDE);
	}else {
		// ...
	}
}


bool FileExists(const char *fname){

	return access(fname, 0) != -1;
}

void CheckProcess(ALL_PROCESS  main_obj){
	/*
	 * 0. GetProcessList
	 * 1. вызываем фрэнд NumberOfLines
	 * 2. Создаём временный массив объектов *temp
	 * 3. Вызываем парсер
	 * 4. Получили массив объектов который надо сравнить с главным
	 * 5. если в темп отсутствует что-то - то в носим в ещё один массив ? для записи в лог
	 * 6. другой цикл - если прибавилось то вносим в существующий ?
	 * 7. деструктор  *темп
	 */

	GetProcessList();


	ALL_PROCESS  temp;

	GetNameAndMemory(temp.Value_P_List() , temp.GetVectorAllProcess());

	WriteChangesToLOG( main_obj.GetVectorAllProcess() , temp.GetVectorAllProcess() );


	temp.~ALL_PROCESS();
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {

	// @TODO: добавить большей свободы в передаче параметров в main()

	int time = 3*1000; // 3sec
	//time = atoi(argv[1]);


	// в автозагрузку будет передаваться параметр '-e' -> следовательно файл включился первый раз при загрузке ОС
	//bool is_exist = (strcmp(argv[2], "-e")) ? true : false;
	bool is_exist = true;

	ALL_PROCESS main_obj = Initialization(is_exist);

	while(1){


		Timer(time);
		CheckProcess(main_obj);

		// ...
	}

	remove(exist); // хз сработает ли когда выключение компьютера
	return 0;
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////
// просто так..вдруг понадобится
/*
char *AppTitle="Win1";
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

int WinMain(HINSTANCE,HINSTANCE,LPSTR,int)
{
  MessageBox(0,"Hello, Windows","MinGW Test Program",MB_OK);
  return 0;
}
*/
