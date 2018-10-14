#include"charpter12.h"
using  namespace std;
void process(shared_ptr<int> ptr) {

}
int main() {
	/*shared_ptr<string> p1;
	shared_ptr<int> p2;
	shared_ptr<int> p3 = make_shared<int>(42);
	shared_ptr<string> p4 = make_shared<string>(10, '9');
	shared_ptr<int> p5 = make_shared<int>();
	auto p = make_shared<int>(42);
	auto q(p);
	if (p1 && (p1->empty()))
		*p1 = "hi";*/

	/*StrBlob b1;
	StrBlob b2 = { "a","an","the" };
	b1 = b2;
	b2.push_back("about");*/
	int* p = new int;
	vector<int>* pv = new vector<int>{ 0,1,2,3,4 };
	shared_ptr<int> p1 = make_shared<int>(42);
	shared_ptr<int> p2(new int(42));
	allocator<string> alloc;

	return 0;
}