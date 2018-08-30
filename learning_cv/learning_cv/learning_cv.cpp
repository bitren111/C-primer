#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;
int main() {

	map<string, size_t> word_count;
	set<string> exclude = { "The","But","And","Or","An","A" };
	map<string, string> author = { {"Joyce","James"},{"Austen","Jane"},{"Dickens","Charles"} };
	string word;

	while (cin >> word) {
		if(exclude.find(word)==exclude.end())
			++word_count[word];
	}
	for (const auto &w : word_count) {
		cout << w.first << " occurs " << w.second
			<< ((w.second > 1) ? " times" : " time") << endl;
	}
	system("pause");
	return 0;
}