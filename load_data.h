#include <iostream>
#include <list>
#include "Book.h"
#include "User.h"
#include "Manager.h"


// 从文件加载书籍数据
std::list<Book> load_book(std::istream &book_file);

// 从文件加载用户数据
std::list<User> load_user(std::istream &user_file);

// 从文件加载管理员数据
std::list<Manager> load_manager(std::istream &manager_file);
