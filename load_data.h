#include <iostream>
#include <list>
#include "Book.h"
#include "User.h"
#include "Manager.h"


// ���ļ������鼮����
std::list<Book> load_book(std::istream &book_file);

// ���ļ������û�����
std::list<User> load_user(std::istream &user_file);

// ���ļ����ع���Ա����
std::list<Manager> load_manager(std::istream &manager_file);
