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
	// �û���¼
	friend std::list<User>::iterator search_user(std::list<User> &users);
	User(std::string n, std::string p) : name(n), passwd(p) {}		// ���캯��
	void user_menu();
	void lookup_book();
	void borrow_book();
	void return_book();
	void getDescription();						// ��������鼮������
	void reset_passwd();						// ��������

private:
	std::string name;
	std::string passwd;
	std::list<Book*> borrow_list;
	std::string message;
};


// �����û�
std::list<User>::iterator search_user(std::list<User> &users);

// �û���¼



#endif