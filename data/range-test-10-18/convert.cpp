#include <iostream>
#include <fstream>

using namespace std;

ifstream Reader;
ofstream Writer;
int a;
double b;
double b_old=0;
int counter = 0;

int main(int argc, char const *argv[])
{
	Reader.open("G23A_sf5_400khz");
	Writer.open("converted.txt");

	if(Reader.is_open()){
		while(1){
			Reader >> a >> b;
			if(b_old > b){
				counter++;
			}
			b_old = b;
			if(Reader.eof()){
				break;
			}
			cout << a << "\t"<< 2*(b + counter*65535)/65535 << endl;
			Writer << a << "\t"<< 2*(b + counter*65535)/65535 << endl;
		}
	}



	return 0;
}