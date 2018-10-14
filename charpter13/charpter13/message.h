#pragma once
#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>
class Folder;
class Message
{
	friend class Folder;
public:
	explicit Message(const std::string& str=" "):
		contents(str) { }
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	void remove(Folder&);
	void save(Folder&);
private:
	std::string contents;
	std::set<Folder> folders;
	void add_to_Folders(const Message&);
	void remove_from_folders();
};
void Message::save(Folder& f) {
	folders.insert(f);
	f.addMsg(this);
}
class Folder {
public:

};
#endif // !MESSAGE_H
