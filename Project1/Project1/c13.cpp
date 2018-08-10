#include"c13.h"
void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::add_to_Folders(const Message& m) {
	for (auto f : m.folders)
	{
		f->addMsg(this);
		
	}
}

Message::Message(const Message& m):
	contents(m.contents),folders(m.folders)
{
	add_to_Folders(m);
}

void Message::remove_from_Folders() {
	for (auto f : folders)
		f->remMsg(this);
}

Message::~Message() {
	remove_from_Folders();
}

Message& Message::operator=(const Message& rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

void swap(Message& lhs, Message& rhs) {
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
}

Folder::Folder(const Folder& f): msgs(f.msgs)
{
	add_to_Message(f);
}

Folder& Folder::operator=(const Folder& f) {
	remove_from_Message();
	msgs = f.msgs;
	add_to_Message(f);
	return *this;
}
Folder::~Folder() {
	remove_from_Message();
}

void Folder::add_to_Message(const Folder& f) {
	for (auto m : f.msgs)
		m->addFldr(this);
}

void Folder::remove_from_Message() {
	for (auto m : msgs)
		m->remove(*this);
}


void swap(Folder& fl, Folder& fr) {
	using std::swap;
	fl.remove_from_Message();
	fr.remove_from_Message();
	swap(fl.msgs, fr.msgs);

}
void Folder::print_debug() {
	for (auto m : msgs)
		std::cout << m->contents << " ";
	std::cout << std::endl;
}

void Message::print_debug() {
	std::cout << contents << std::endl;
}