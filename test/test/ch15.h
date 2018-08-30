#pragma once
#ifndef CH15_H
#define CH15_H
#include<string>
#include<iostream>
#include<string>
using namespace std;
class Quote
{
public:
	Quote() = default;
	Quote(const string& book, double price) :
		bookNo(book), price(price) { }
	Quote(const Quote& q) : bookNo(q.bookNo), price(q.price){}
	virtual void debug(ostream& os) {
		os << bookNo << " " << price << endl;
	};
	std::string isbn() const { return bookNo; };
	virtual double net_price(std::size_t n) const {
		return n*price;
	};
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0;
};
class Bulk_quote :public Quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string& book, double p, size_t qty, double disc) :
		Quote(book, p), min_qty(qty), discount(disc) {}
	double net_price(std::size_t) const override;
private:
	size_t min_qty = 0;
	double discount = 0.0;
};
double Bulk_quote::net_price(std::size_t cnt) const {
	if (cnt >= min_qty)
		return cnt*(1 - discount)*price;
	else
		return cnt*price;
}
double print_total(ostream& os, const Quote& item, size_t n) {
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
	return ret;
}
#endif // !CH15_H
