#include "load_data.h"
#include <sstream>

std::list<Book> load_book(std::istream &book_file) {
	std::list<Book> b;
	std::string line;
	while (getline(book_file, line)) {
		std::istringstream recode(line);
		std::string s1, s2, s3;
		recode >> s1 >> s2 >> s3;
		b.emplace_back(s1, s2, s3);
	}
	return b;
}

std::list<User> load_user(std::istream &user_file) {
	std::list<User> u;
	std::string line;
	while (getline(user_file, line)) {
		std::istringstream recode(line);
		std::string s1, s2;
		recode >> s1 >> s2;
		u.emplace_back(s1, s2);	
	}
	return u;
}

std::list<Manager> load_manager(std::istream &manager_file) {
	std::list<Manager> m;
	std::string line;
	while (getline(manager_file, line)) {
		std::istringstream recode(line);
		std::string s1, s2;
		recode >> s1 >> s2;
		m.emplace_back(s1, s2);	
	}
	return m;
}