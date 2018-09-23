#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <chrono>
#include <ratio>
#include "Manager.h"
#include "User.h"


class Book {
public:
	friend void User::borrow_book();
	friend void User::return_book();
	friend class Manager;
	typedef std::chrono::system_clock::time_point tm;
	static const std::chrono::duration<unsigned, std::ratio<24 * 60 * 60>> days;	// Ĭ�Ͻ���ʱ��
	Book(std::string aname, std::string aisbn, std::string a_author):
			name(aname), isbn(aisbn), author(a_author) { }
	std::string getName() const;
	void description() const;		// ������ڸ������Ϣ

private:
	void modify_info();				// �޸��鼮��Ϣ
	std::string name;
	std::string isbn;
	std::string author;
	bool borrow = false;
	tm return_time;
};

// �����鼮
std::list<Book>::iterator search_book(std::list<Book> &books);

#endif