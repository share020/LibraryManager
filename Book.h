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
	static const std::chrono::duration<unsigned, std::ratio<24 * 60 * 60>> days;	// 默认借阅时长
	Book(std::string aname, std::string aisbn, std::string a_author):
			name(aname), isbn(aisbn), author(a_author) { }
	std::string getName() const;
	void description() const;		// 输出关于该书的信息

private:
	void modify_info();				// 修改书籍信息
	std::string name;
	std::string isbn;
	std::string author;
	bool borrow = false;
	tm return_time;
};

// 查找书籍
std::list<Book>::iterator search_book(std::list<Book> &books);

#endif