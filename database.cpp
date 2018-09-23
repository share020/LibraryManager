#include <fstream>
#include "load_data.h"

std::ifstream book_file("book_file.txt"), user_file("user_file.txt"),
	manager_file("manager_file.txt");
extern std::list<Book> books = load_book(book_file);
extern std::list<User> users = load_user(user_file);
extern std::list<Manager> managers = load_manager(manager_file);
