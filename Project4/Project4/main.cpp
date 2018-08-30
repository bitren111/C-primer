#include <iostream>
#include<map>
#include<string>
#include <algorithm>
#include <vector>
#include<utility>
using std::string;
using std::vector;
using std::map;
using std::cin;
using std::cout;
using Families = map<string, vector<string>>;

auto make_families() {
	Families families;
	for (string ln; cout << "Last name:\n", cin >> ln&&ln != "@q";) {
		for (string cn; cout << "Last name:\n", cin >> cn&&cn != "@q";)
			families[ln].push_back(cn);
		return families;
	}
}

auto print(Families const& families)
{
	for (auto const& family : families)
	{
		cout << family.first << ":\n";
		for (auto const& child : family.second)
			cout << child << " ";
		cout << "\n";
	}
}

auto saves(vector<string>& s, vector<int>& p) {
	vector<std::pair<string, int>> temp;
	if (!s.empty()) {
		for (int i = 0; i != s.size(); i++) {
			temp.push_back({ s[i], p[i] });
		}
		return temp;
	}
	return temp;
}

int main()
{
	print(make_families());
	return 0;
}