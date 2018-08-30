#pragma once
#ifndef C09_H
#define C09_H
#include<list>
#include<deque>
#include<vector>
#include<array>
std::list<std::deque<int>> p;
std::vector<int>::iterator
find(std::vector<int>::iterator b, std::vector<int>::iterator e, int num) {
	while (b != e) {
		if (num == *b)
			return b;
		++b;
	}
	return e;
}
#endif // !C09_H
