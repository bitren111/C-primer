#pragma once
#ifndef C13_H
#define C13_H
#include<string>
#include<set>
class Folder {

};
class Message {
friend void swap(Message&,Message&);
public:
	explicit Message(const std::string& str=""):
		contents(str){}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message() ;
	void save(Folder&);
	void remove(Folder&);
private:
	std::string contents;
	std::set<Folder*> folders;
	void add_to_Folders(const Message&);
	void remove_from_Folders();
};
void swap(Message&, Message&);
#endif // !C13_H
