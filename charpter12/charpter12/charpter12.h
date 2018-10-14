#pragma once
#ifndef CHARPTER12_H
#define CHARPTER12_H
#include<vector>
#include<string>
#include<memory>
class StrBlobPtr;
class StrBlob
{
friend StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob() :data(std::make_shared<std::vector<std::string>>()){}
	StrBlob(std::initializer_list<std::string> il) :data(std::make_shared<std::vector<std::string>>(il)){}
	size_type size() const{ return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();

	StrBlobPtr begin() { return StrBlobPtr(*this); }
	StrBlobPtr end() { return StrBlobPtr(*this, data->size()); }
	std::string& front();
	std::string& back();
	std::string& front() const;
	std::string& back() const;
private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};

class StrBlobPtr {
public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz=0):
		wptr(a.data),curr(sz){}
	std::string& deref() const;
	StrBlobPtr& incr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;
	std::weak_ptr<std::vector<std::string>> wptr;
	std::size_t curr;
};

#endif // !CHARPTER12_H
