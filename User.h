#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <list>
#include "Manager.h"

class Book;

class User {
public:
	friend class Manager;
	// 用户登录
	friend std::list<User>::iterator search_user(std::list<User> &users);
	User(std::string n, std::string p) : name(n), passwd(p) {}		// 构造函数
	void user_menu();
	void lookup_book();
	void borrow_book();
	void return_book();
	void getDescription();						// 输出所借书籍的描述
	void reset_passwd();						// 重设密码

private:
	std::string name;
	std::string passwd;
	std::list<Book*> borrow_list;
	std::string message;
};


// 查找用户
std::list<User>::iterator search_user(std::list<User> &users);

// 用户登录



#endif