#include <sstream>
#include <chrono>
#include <algorithm>
#include "database.h"
#include "Book.h"
#include "User.h"
#include "interface.h"


// 用户界面
void User::user_menu() {
	while (true) {
		console_clear();
		std::cout << "\n\t\t\t";
		std::cout << "0: lookup book" << "\t\t\t" << "1: check information";
		std::cout << "\n\t\t\t";
		std::cout << "2: borrow book" << "\t\t\t" << "3: return book";
		std::cout << "\n\t\t\t";
		std::cout << "4: reset password" << "\t\t" << "5: exit";
		std::cout << "\n\t\t\t";
		std::cout << "your choice: ";

		int choice;
		bool flag = false;
		while (!flag) {
			std::cin >> choice;
			switch (choice) {
			case 0:
			{
				flag = true;
				console_clear();
				std::cout << "lookup book: " << std::endl;
				lookup_book();
				return_or_not();
				break;
			}

			case 1:
			{
				flag = true;
				console_clear();
				std::cout << "check information: " << std::endl;
				getDescription();
				return_or_not();
				break;
			}

			case 2:
			{
				flag = true;
				console_clear();
				std::cout << "borrow book: " << std::endl;
				borrow_book();
				return_or_not();
				break;
			}

			case 3:
			{
				flag = true;
				console_clear();
				std::cout << "return book: " << std::endl;
				return_book();
				return_or_not();
				break;
			}

			case 4:
			{
				flag = true;
				console_clear();
				std::cout << "reset password: " << std::endl;
				reset_passwd();
				return_or_not();
				break;
			}
			
			case 5:
			{
				flag = true;
				console_clear();
				return;
			}

			default:
				break;
			}
		}
	}
	
}


// 查找书籍
void User::lookup_book() {
	bool flag = false;
	while (!flag) {
		auto it = search_book(books);
		if (it == books.end())
			std::cout << "not found!" << std::endl;
		else
			return (*it).description();
	}
}

void User::borrow_book() {
	auto it = search_book(books);
	if (it != books.end() && !(it->borrow)) {
		borrow_list.push_back(&(*it));
		Book::tm today = std::chrono::system_clock::now();
		it->borrow = true;
		it->return_time = today + Book::days;
	}
	else
		std::cerr << "Error! It was not in stock." << std::endl;
}

void User::return_book()
{
	std::cout << "please enter book's name: ";
	std::string name;
	std::cin >> name;
	auto it = find_if(borrow_list.begin(), borrow_list.end(),
		[name](Book *p) { return name == p->name; });
	if (it == borrow_list.end())
		std::cerr << "Error! You havn't borrowed this book." << std::endl;
	else
	{
		(*it)->borrow = false;
		//(*it)->return_time = Book::tm();
		borrow_list.erase(it);	
	}
}

void User::getDescription()
{
	std::cout << "name:" << name << std::endl
		<< "borrow_list:" << std::endl;
	for (auto b = borrow_list.cbegin(); b != borrow_list.cend(); ++b)
		(*b)->description();
}

void User::reset_passwd()
{
	std::string first = "", second = "";	
	while (!first.empty() && !second.empty()) {	
		if (first != second) {
			std::cout << "please enter your new password:";
			std::cin >> first;
			std::cout << "please verify your new password:";
			std::cin >> second;
		}
		else
			passwd = first;
	}
}
