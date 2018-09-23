#include <iostream>
#include "Book.h"

const std::chrono::duration<unsigned, std::ratio<24 * 60 * 60>> Book::days(60);	// ΩË‘ƒ ±≥§

void Book::description() const
{
	std::cout << "name: " << name << std::endl
		<< "isbn: " << isbn << std::endl
		<< "author: " << author << std::endl
		<< "borrow status: " << (borrow ? "borrowed " : "in stock") << std::endl;
		if (borrow) {
			std::cout << "return_time: ";
			std::cout << std::chrono::system_clock::to_time_t(return_time) << std::endl;
		}
		else {
			std::cout << "return_time: -" << std::endl;
		}
}

void Book::modify_info() {
	description();
	std::string a_name, a_isbn, a_author;
	std::cout << "please enter new name, new isbn, and new author: ";
	std::cin >> a_name >> a_isbn >> a_author;
	if (a_name.empty() || a_isbn.empty() || a_author.empty())
	{
		std::cout << "Error! your input is not standard" << std::endl;
		return;
	}
	else
	{
		name = a_name;
		isbn = a_isbn;
		author = a_author;
	}
		
}

std::string Book::getName() const {
	return name;
}