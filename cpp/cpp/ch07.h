#pragma once
#ifndef CH07_H
#define CH07_H
#include <iostream>
#include <string>
#include<vector>
class Sales_data
{	//友元
	friend Sales_data add(const Sales_data&, const Sales_data&);
	friend std::ostream& print(std::ostream&, const Sales_data&);
	friend std::istream& read(std::istream&, Sales_data&);
public:
	//构造
	/*Sales_data() = default;
	Sales_data(const std::string &s) : bookNo(s){}*/
	Sales_data(const std::string &s, unsigned cnt, double p) :
		bookNo(s), unit_sold(cnt), revenue(p*cnt){}
	Sales_data() :Sales_data("", 0,0){}
	explicit Sales_data(std::string& s):Sales_data(s,0,0){}
	
	//函数
	explicit Sales_data(std::istream&);
	std::string isbn() const { return bookNo; };
	Sales_data& combine(const Sales_data&);
private:

	double avg_price() const;
	std::string bookNo;
	unsigned unit_sold = 0;
	double revenue = 0.0;
};

Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&); //Sales_data 不能是const的啊

class Screen;
class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	ScreenIndex addScreen(const Screen&);
	void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};

class Screen {
friend Window_mgr;
public:
	typedef std::string::size_type pos;
	//using pos = std::string::size_type;
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht*wd, c){}
	char get() const { return contents[cursor]; }
	char get(pos r, pos c) const;
	Screen& move(pos r, pos c);
	void some_member()const {
		std::cout << ++access_ctr << std::endl;
	}
	Screen& set(char);
	Screen& set(pos, pos, char);
	Screen& display(std::ostream& os) {
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const{
		do_display(os);
		return *this;
	}


private:
	pos cursor=0;
	pos height = 0, width = 0;
	std::string contents;
	mutable size_t access_ctr=0;
	void do_display(std::ostream& os) const{
		os << contents;
	}
};

class Account {
public:
	void calculate() {
		amount += amount*interestRate;
	}
	static double rate() { return interestRate; }
	static void rate(double newRate) {
		interestRate = newRate;
	}
private:
	std::string owner;
	double amount;
	static double interestRate;
};

#endif // !CH07_H
