#include "interface.h"
#include "login.h"
#include <iostream>

// 清屏
void console_clear() {
	system("cls");
	std::cout << std::endl << std::endl << std::endl;
	std::cout << "\t\t\t";
}


// 返回上级菜单
void return_or_not() {
	std::cout << "enter y to return: ";
	char ch;
	std::cin >> ch;
	if (ch == 'y')
		system("cls");
	else
		return;
}


// 主菜单
void main_menu() {
	console_clear();
	std::cout << "welcome to Eric's Library" << std::endl;
	std::cout << "\t\t\t" << "0: user login" << "\t\t\t" << "1: manager login" << std::endl;
	std::cout << "\t\t\t" << "2: exit" << std::endl;
	std::cout << "\t\t\t" << "your choice: ";
	int choice;
	bool flag = false;
	while (!flag) {
		std::cin >> choice;
		switch (choice) {
		case 0:
		{
			flag = true;
			console_clear();
			User &u = user_login();
			u.user_menu();
			break;
		}
			
		case 1:
		{
			flag = true;
			console_clear();
			Manager& m = manager_login();
			m.manager_menu();
			break;
		}

		case 2:
		{
			flag = true;
			return;
			break;
		}

		default:
		{
			std::cout << "Error! Please enter again:";
			break;
		}
			
		}
	}
}
