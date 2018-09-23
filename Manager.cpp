#include <iostream>
#include <fstream>
#include "Manager.h"
#include "Book.h"
#include "interface.h"



// 管理员界面
void Manager::manager_menu() {
	while (true) {
		console_clear();
		std::cout << "0: lookup book" << "\t\t\t" << "1: upload book";
		std::cout << "\n\t\t\t";
		std::cout << "2: offload book" << "\t\t\t" << "3: add user";
		std::cout << "\n\t\t\t";
		std::cout << "4: delete user" << "\t\t\t" << "5: update book information";
		std::cout << "\n\t\t\t";
		std::cout << "6: reset password" << "\t\t" << "7: backup database";
		std::cout << "\n\t\t\t";
		std::cout << "8: exit";
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
				std::cout << "upload book: " << std::endl;
				upBook();
				return_or_not();
				break;
			}

			case 2:
			{
				flag = true;
				console_clear();
				std::cout << "offload book: " << std::endl;
				offBook();
				return_or_not();
				break;
			}

			case 3:
			{
				flag = true;
				console_clear();
				std::cout << "add user: " << std::endl;
				addUser();
				return_or_not();
				break;
			}

			case 4:
			{
				flag = true;
				console_clear();
				std::cout << "delete user: " << std::endl;
				deleteUser();
				return_or_not();
				break;
			}

			case 5:
			{
				flag = true;
				console_clear();
				std::cout << "update book information: " << std::endl;
				updateBook();
				return_or_not();
				break;
			}

			case 6:
			{
				flag = true;
				console_clear();
				std::cout << "reset password: " << std::endl;
				reset_passwd();
				return_or_not();
				break;
			}

			case 7:
			{
				flag = true;
				console_clear();
				std::cout << "backup database: " << std::endl;
				backup();
				return_or_not();
				break;
			}

			case 8:
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
void Manager::lookup_book() {
	bool flag = false;
	while (!flag) {
		auto it = search_book(books);
		if (it == books.end())
			std::cout << "not found!" << std::endl;
		else
		{
			flag = true;
			it->description();
		}
	}
}

// 上架书籍
void Manager::upBook() {
	bool flag = false;	
	while (!flag) {
		auto it = search_book(books);
		if (it != books.end())
			std::cout << "This book exists!" << std::endl;
		else
		{
			flag = true;	
			std::string a_name, a_isbn, a_author;
			bool valid = true;
			while (valid) {
				std::cout << "please enter book's information: " << std::endl;
				std::cout << "\t\t\t" << "book name: ";
				std::cin >> a_name;
				std::cout << "\t\t\t" << "book isbn: ";
				std::cin >> a_isbn;
				std::cout << "\t\t\t" << "book author: ";
				std::cin >> a_author;
				valid = a_name.empty() || a_isbn.empty() || a_author.empty();
			}
			books.emplace_back(a_name, a_isbn, a_author);
		}
	}	
}

// 下架书籍
void Manager::offBook() {
	bool flag = false;
	while (!flag) {
		auto it = search_book(books);
		if (it == books.end())
			std::cout << "not found!" << std::endl;
		else {
			flag = true;
			books.erase(it);
		}
	}		
}

void Manager::addUser() {
	bool flag = false;
	while (!flag) {
		auto it = search_user(users);
		if (it != users.end())
			std::cout << "user exists!" << std::endl;
		else {
			flag = true;
			std::string a_name, a_psw;
			bool valid = true;	
			while(valid){
				std::cout << "\t\t\t" << "please enter user's information: " << std::endl;
				std::cout << "\t\t\t" << "username: ";
				std::cin >> a_name;
				std::cout << "\t\t\t" << "password: ";
				std::cin >> a_psw;
				valid = a_name.empty() || a_psw.empty();
			}
			users.emplace_back(a_name, a_psw);
		}
	}
	
}

void Manager::deleteUser() {
	bool flag = false;
	while (!flag) {
		auto it = search_user(users);
		if (it == users.end())
			std::cout << "not found!" << std::endl;
		else
		{
			flag = true;
			users.erase(it);	
		}
	}
}

void Manager::updateBook() {
	bool flag = false;
	while (!flag) {
		auto it = search_book(books);
		if (it == books.end())
			std::cout << "not found!" << std::endl;
		else {
			flag = true;
			it->modify_info();
		}
	}
}


void Manager::backup() const
{
	std::ofstream book_file("books_backup.txt"),
		user_file("users_backup.txt");

	if (book_file && user_file) {
		for (const auto &b : books)
			book_file << b.name << " " << b.isbn << " " << b.author << std::endl;
		for (const auto &u : users)
			user_file << u.name << " " << u.passwd << std::endl;
	}
	else
		std::cerr << "couldn't open files!" << std::endl;
}

void Manager::reset_passwd() {
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