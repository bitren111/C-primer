#include"ch08.h"
#include<iostream>
using namespace std;
int main() {
	/*const StrBlob csb{ "hello","world","pezy" };
	StrBlob sb{ "hello","world","Moophy" };
	std::cout << csb.front() << " " << csb.back() << std::endl;
	sb.back() = "pezy";
	std::cout << sb.front() << " " << sb.back() << std::endl;*/
	int* ps = new int;
	string* ps = new string(10, '9');
	int* p2 = new (nothrow) int;

	system("pause");
	return 0;
}
