#include "login.h"
#include "database.h"

User& user_login() {
	bool flag = false;
	while (!flag) {
		auto it = search_user(users);
		if (it == users.end())
			std::cout << "not found! " << std::endl;
		else {
			flag = false;
			return *it;
		}
	}
}

Manager& manager_login() {
	bool flag = false;
	while (!flag) {
		auto it = search_manager(managers);
		if (it == managers.end())
			std::cout << "not found!" << std::endl;
		else {
			flag = true;
			return *it;
		}
	}	
}