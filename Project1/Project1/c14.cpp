#include"c14.h"

StrVec::StrVec() :elements(nullptr), first_free(nullptr),cap(nullptr){}

StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = rhs.elements;
	first_free = rhs.first_free;
	return *this;
}

StrVec::~StrVec() {
	free();
}

void StrVec::push_back(const std::string& s) {
	chk_n_allocator();
	alloc.construct(first_free++, s);
}

std::size_t StrVec::size() const {
	return first_free - elements;
}

std::size_t StrVec::capacity() const {
	return cap - elements;
}

std::string* StrVec::begin() const {
	return elements;
}

std::string* StrVec::end() const {
	return first_free;
}

void StrVec::chk_n_allocator() {
	if (size() == capacity())
		reallocate();
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e) {
	auto data = alloc.allocate(e - b);
	return{ data, std::uninitialized_copy(b,e,data) };
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
		alloc.deallocate(elements, cap - elements);
	}
}

void StrVec::reallocate() {
	auto newcapicity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapicity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapicity;
}

