#include<algorithm>
#include<vector>
#include<iostream>
#include<numeric>
#include<iterator>
#include<string>
#include<functional>
#include<iterator>
#include<list>
using namespace std::placeholders;
using std::vector; using std::string;
bool isShorter(const std::string& a, const std::string& b) {
	return (a.size() > b.size() ? 1 : 0);
}
void elimDups(vector<string>& words) {
	std::stable_sort(words.begin(),words.end(),isShorter);
	auto end_unique = std::unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
}
void biggies(vector<string>&, vector<string>::size_type);
bool check_size(string const& str, std::size_t sz)
{
	return str.size() < sz;
}
bool isLesserThanOrEqualTo6(const string &s, string::size_type sz)
{
	return s.size() < sz;
}
int main_c() {
	std::ostream_iterator<int> out_iter(std::cout, " ");
	//vector<string> p{ "gaoqian","hit",".edu.cn" };
	vector<int> num{ 1,2,3,4,5,6,7,8,9 };
	for (auto i : num)
		*out_iter++ = i;
	std::cout << std::endl;

	/*vector<int> num1, num2;
	std::list<int> num3;
	std::copy(num.cbegin(), num.cend(), std::inserter(num1, num1.begin()));
	for (auto i = num1.cbegin(); i != num1.cend(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::copy(num.cbegin(), num.cend(), std::back_inserter(num2));
	for (auto i = num2.cbegin(); i != num2.cend(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	std::copy(num.cbegin(), num.cend(), std::front_inserter(num3));
	for (auto i = num2.cbegin(); i != num2.cend(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;*/
	//std::cout << std::count_if(authors.cbegin(), authors.cend(), bind(isLesserThanOrEqualTo6, _1, 6)) << std::endl;
	/*auto f = std::count_if(p.begin(), p.end(), [](string s) {return s.size() > 6; });
	int i = 7;
	auto check_and_decrement = [&i](){return i > 0 ? !--i : !i; };
	std::cout << "ex10.21: ";
	while (!check_and_decrement())
		std::cout << i << " ";
	std::cout << i << std::endl;
	std::cout << f << std::endl;*/
	system("pause");
	return 0;
}

void biggies(vector<string>& words, vector<string>::size_type sz) {
	elimDups(words);
	std::stable_sort(words.begin(), words.end(), [](const string& a, const string& b) {return a.size() < b.size(); });
	auto wc = std::find_if(words.begin(), words.end(), [sz](const string& a) {return a.size() > sz; });
	auto count = words.end() - wc;

}