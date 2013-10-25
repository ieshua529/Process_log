
#include "all_process.h"

ALL_PROCESS::ALL_PROCESS() {

	// первым делом зафиксируем время
	currentTime.SET_TIME( );

	// !!!!!Инициализировать log & p_list !!!!!


	all_process = new PROCES;
		if(!all_process) {
			// записать в лог сообщение об ошибке и выйти...а лучше попробовать ещё раз
		}

}

void Parser(){

}

bool WriteToLog(){

	return true;
}

ALL_PROCESS::~ALL_PROCESS(){

}
