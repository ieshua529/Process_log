
#include "string" //wtf
#include <fstream>
using namespace std;//вообще всё по новому:)))
class Process_log {
	string str;
	int Hr;
	int Min;
	int Sec;
	int Day;
	int Month;
	int Year;
public:
	//void  setName (string);
	void  setTime (int , int , int);
	void  setDate (int , int ,int );
	string  GetString ();
	void  Backup ();
	Process_log (){
		str  = '0';
		Hr = 0;
		Min = 0;
		Sec = 0;
		Year = 0;
		Day = 0;
		Month  = 0;
	}
	//наведи на это проект
};

// void Process_log:: setName (string s) {
//	 str = s;
//}

  void Process_log :: setTime (int H, int M, int S){
	  Hr = H;
	  Min = M;
	  Sec = S;
  }

  void Process_log :: setDate (int Y , int M , int D){
	  Year = Y;
	  Day = D;
	  Month = M;
  }
  void Process_log :: Backup (){
	  ofstream f("BackUp.txt",ios::in|ios::app);
	  f<<str<<" "<<Year<<" "<<Month<<" "<<Day<<' '<<Hr<<" "<<Min<<" "<<Sec<<'\n';
  }

  /*string Process_log :: GetString () {
	  ifstream f("C://1.txt");
	  string s1;
	  while (f>>s1)
		  str = s1;
	  return str;
  }*/
  void main(){

  }