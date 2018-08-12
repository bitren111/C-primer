#pragma once
#ifndef C14_H
#define C14_H

#include <string>
#include<memory>
#include<utility>
class StrVec {
public:
	StrVec()=default;
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(StrVec&&) noexcept;
	void push_back(const std::string&);
	std::size_t size() const;
	std::size_t capacity() const;
	std::string* begin() const;
	std::string* end() const;

	void reserve(size_t new_cap);
	void resize(size_t count);
	void resize(size_t count, const std::string&);

private:
	static std::allocator<std::string> alloc;
	void chk_n_allocator();

	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*) ;
	void free();
	void reallocate();
	std::string *elements;
	std::string *first_free;
	std::string *cap;
};
#endif // !C14_H
