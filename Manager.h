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
	// ����Ա��¼
	friend std::list<Manager>::iterator search_manager(std::list<Manager> &managers);
	Manager(std::string n, std::string p) :
		name(n), passwd(p) {}

	// ����Ա����
	void manager_menu();

	// �����鼮
	void lookup_book();
	
	// �鼮�ϼ�
	void upBook();

	// �鼮�¼�
	void offBook();

	// �¼��û�
	void addUser();

	// ɾ���û�
	void deleteUser();

	// �����鼮��Ϣ
	void updateBook();

	void reset_passwd();

	// �������ݵ��ļ���
	void backup() const;


private:
	std::string name;
	std::string passwd;
	std::list<Book> &books = ::books;				// �鼮���������
	std::list<User> &users = ::users;				// �û����������
};


// ���ҹ���Ա
std::list<Manager>::iterator search_manager(std::list<Manager> &managers);

// ����Ա��¼
Manager& manager_login();

#endif