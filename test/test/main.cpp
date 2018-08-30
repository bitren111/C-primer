#include<iostream>
#include<vector>
#include<string>
#include"a09.h"
using namespace std;
int main() {
	vector<int> p = {10,7,5,2,6};
	for (auto i : p)
		cout << i << " ";
	cout << endl;
	cout << random_select(p, 0, p.size() - 1, 1) << endl;
	for (auto i : p)
		cout << i << " ";
	cout << endl;
	system("pause");
	return 0;
}