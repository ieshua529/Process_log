
#include "string" //wtf
#include <fstream>
using namespace std;
class Hron {
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
	Hron (){
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

// void Hron:: setName (string s) {
//	 str = s;
//}

  void Hron :: setTime (int H, int M, int S){
	  Hr = H;
	  Min = M;
	  Sec = S;
  }

  void Hron :: setDate (int Y , int M , int D){
	  Year = Y;
	  Day = D;
	  Month = M;
  }
  void Hron :: Backup (){
	  ofstream f("BackUp.txt",ios::in|ios::app);
	  f<<str<<" "<<Year<<" "<<Month<<" "<<Day<<' '<<Hr<<" "<<Min<<" "<<Sec<<'\n';
  }

  /*string Hron :: GetString () {
	  ifstream f("C://1.txt");
	  string s1;
	  while (f>>s1)
		  str = s1;
	  return str;
  }*/
  void main(){

  }