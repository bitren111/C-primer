#include"c08.h"
#include"c09.h"

class People {
public:
	string name;
	vector<string> phones;
};
int mainp() {
	/*string line, word;
	vector<People> people;
	ifstream ifs("./phone.txt");
	while (std::getline(ifs, line)) {
		People info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
			info.phones.push_back(word);
		people.push_back(info);
	}*/
	/*std::vector<int> p{ 1,2,3,4,5,6,7 };
	p.assign(5, 10);
	for (auto i = p.begin(); i != p.end(); ++i) {
		std::cout << *i << std::endl;
	}*/
	std::string s;
	std::deque<string> ds;
	while (std::cin >> s) {
		ds.push_back(s);
	}
	for (auto dds = ds.begin(); dds != ds.end(); ++dds) {
		std::cout << *dds << std::endl;
	}
	system("pause");
	return 0;
}

void ReadFileToVector(const string& fileName, vector<string>& vec) {
	ifstream ifs(fileName,std::ifstream::in);
	if (ifs) {
		string buff;
		while (std::getline(ifs,buff))
			vec.push_back(buff);
	}
}

std::iostream& rd(std::iostream& is) {
	string temp;
	while (is >> temp)
		std::cout << temp << std::endl;
	is.clear();
	return is;
}

