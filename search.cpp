#include "Book.h"
#include "User.h"
#include "Manager.h"
#include <iostream>
#include <string>
#include <algorithm>

std::list<Book>::iterator search_book(std::list<Book> &books) {
	std::cout << "please enter book name: ";
	std::string name;
	std::cin >> name;
	auto it = find_if(books.begin(), books.end(),
		[name](Book &b) { return b.getName() == name; });
	return it;
}

std::list<User>::iterator search_user(std::list<User> &users) {
	std::string name, psw;
	std::cout << "please enter username: ";
	std::cin >> name;
	std::cout << "\t\t\t";
	std::cout << "please enter password: ";
	std::cin >> psw;
	auto it = find_if(users.begin(), users.end(),
		[name, psw](User &u) {return (u.name == name) && (u.passwd == psw); });
	return it;
}

std::list<Manager>::iterator search_manager(std::list<Manager> &managers) {
	std::string name, psw;
	bool flag = false;
	while (!flag) {
		std::cout << "please enter manager name: ";
		std::cin >> name;
		std::cout << "\t\t\t";
		std::cout << "please enter password: ";
		std::cin >> psw;
		auto it = find_if(managers.begin(), managers.end(),
			[name, psw](Manager &m) {return (m.name == name) && (m.passwd == psw); });
		if (it == managers.end())
			std::cout << "manager name or password wrong!" << std::endl;
		else {
			flag = true;
			return it;
		}
	}
}

