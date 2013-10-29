// некоторые команды
/*
 * TASKLIST /FI "USERNAME NE NT AUTORITY\SYSTEM" /FI "STATUS eq running" /FO CSV /NH > process_list
   TASKKILL /IM Process_log.exe

   $ date
   25 окт 2013 г.  1:17:29

 */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////



#include "Process_log_main.h"


void GetProcessList(const char* OS) {

	if(GET_OS_NAME() == "WINDOWS"){

		system("chcp 1251");
		system(tasklist);

	} else if(GET_OS_NAME() == "LINUX"){
		// ...
	}

}


ALL_PROCESS Initialization(const bool is_exist){

	setlocale(0,"");

	// первый раз пооткрываать файлы

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

	HideWindow();
	if(GET_OS_NAME() == "WINDOWS"){
		GetProcessList("WINDOWS");
	}else{
		GetProcessList("LINUX");
	}

	ALL_PROCESS 	main_obj; // как не пёрло мне придумывать нормальное название >___<
	GetNameAndMemory( main_obj.Value_P_List()  , main_obj.Value_All_Process());

	return main_obj;
}

void Timer(const int time){
	if(GET_OS_NAME() == "WINDOWS"){
		Sleep(time);  // winAPI
	}else{
		usleep(time);
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

	if(GET_OS_NAME() == "WINDOWS"){
		GetProcessList("WINDOWS");
	}else{
		GetProcessList("LINUX");
	}

	ALL_PROCESS  temp;

	GetNameAndMemory(temp.Value_P_List() , temp.Value_All_Process());

	WriteChangesToLOG( main_obj , temp );


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
