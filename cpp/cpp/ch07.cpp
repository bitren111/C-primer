#include"ch07.h"
Sales_data& Sales_data::combine(const Sales_data& rhs) {
	unit_sold += rhs.unit_sold;
	revenue += rhs.revenue;
	return *this;
}

double Sales_data::avg_price() const{
	if (unit_sold)
		return revenue / unit_sold;
	else
		return 0;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data Sum = lhs;
	Sum.combine(rhs);
	return Sum;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.unit_sold << " " << item.revenue << " " << item.avg_price();
	return os;

}

std::istream& read(std::istream& is, Sales_data& item) {
	double price = 0;
	is >> item.bookNo >> item.unit_sold >> price;
	item.revenue = price*item.unit_sold;
	return is;
}

Sales_data::Sales_data(std::istream& is) {
	read(is, *this);
}

char Screen::get(pos r, pos c) const {
	return contents[r*width + c];
}

Screen& Screen::move(pos r, pos c) {
	pos row = r*width;
	cursor = row + c;
	return *this;
}

Screen& Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

Screen& Screen::set(pos r, pos col, char ch) {
	contents[r*width + col] = ch;
	return *this;
}

void Window_mgr::clear(ScreenIndex i) {
	Screen& s = screens[i];
	s.contents = std::string(s.height*s.width, ' ');
}

Window_mgr::ScreenIndex 
Window_mgr::addScreen(const Screen& s) {
	screens.push_back(s);
	return screens.size() - 1;
}
