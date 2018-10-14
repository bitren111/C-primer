#include<iostream>
#include<string>
using namespace std;
class Foo {
public:
	Foo()=default;
	Foo(const Foo&);
	Foo& operator=(const Foo&);
	~Foo();
	
};
class HasPtr {
public:
	HasPtr(const string& s= std::string()):
		ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
	HasPtr(const HasPtr& hp): 
		ps(new std::string(*hp.ps)),i(hp.i)
	{}
	HasPtr& operator=(const HasPtr& rhs) {
		auto newp = new std::string(*(rhs.ps));
		delete ps;
		ps = newp;
		i = rhs.i;
		return *this;
	}
	~HasPtr()
	{	delete ps;
	}
private:
	std::string *ps;
	int i;
	std::size_t *use;
};
class NoCopy {
public:
	NoCopy() = default;
	NoCopy(const NoCopy&) = delete;
	NoCopy& operator=(const NoCopy&) = delete;
	~NoCopy() = default;
};
int main() {
	cout << "gaoqian" << endl;
	return 0;
}