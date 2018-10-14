#include"charpter12.h"
void StrBlob::check(size_type i, const std::string& msg) const{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

std::string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
std::string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back() {
	check(0, "front on empty StrBlob");
	return data->back();
}

std::string& StrBlob::back() const {
	check(0, "front on empty StrBlob");
	return data->back();
}

std::shared_ptr<std::vector<std::string>> 
StrBlobPtr::check(std::size_t i, const std::string& msg) const {
	auto ret = wptr.lock();
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}

std::string& StrBlobPtr::deref() const{
	auto p = check(curr, "derefrence past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

