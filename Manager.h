#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <list>
#include "database.h"

class Book;
class User;

class Manager
{
public:
	// 管理员登录
	friend std::list<Manager>::iterator search_manager(std::list<Manager> &managers);
	Manager(std::string n, std::string p) :
		name(n), passwd(p) {}

	// 管理员界面
	void manager_menu();

	// 查找书籍
	void lookup_book();
	
	// 书籍上架
	void upBook();

	// 书籍下架
	void offBook();

	// 新加用户
	void addUser();

	// 删除用户
	void deleteUser();

	// 更新书籍信息
	void updateBook();

	void reset_passwd();

	// 备份数据到文件中
	void backup() const;


private:
	std::string name;
	std::string passwd;
	std::list<Book> &books = ::books;				// 书籍链表的引用
	std::list<User> &users = ::users;				// 用户链表的引用
};


// 查找管理员
std::list<Manager>::iterator search_manager(std::list<Manager> &managers);

// 管理员登录
Manager& manager_login();

#endif