# LibraryManager

## 1 Introduction
This project is written with C++.
Just to exercise the syntax of C++ after the study of ***C++ Primer***.

## 2 Functions Provided

### 2.1 class Book
1. *name*
2. *isbn*
3. *author*
4. *borrow status*
5. *return time:* if the book was borrow, recode when it should be returned.

### 2.2 class Manager
1. *lookup books:* enter the book's name to find the book
2. *upload books:* add a book to the library
3. *offload books*: 
4. *add user*
5. *delete user*
6. *reset password*
7. *backup:* 

### 2.3 class User
1. *lookup books:* enter the book's name to find the book
2. *check self's information:* show self's information, including name, books borrowed.
3. *borrow book:* 
4. *return book:*
5. *reset password:*

## 2.4 relationship between classes
Firstly, all books, all users, and all managers are all stored respectively in list using **C++'s STL std::list**.
class Book just to recode the book's information.
class Manager is friend class of class Book and class User, because managers can modify the books' and users' informations.
class user's two member functions **borrow_book** and **return_book** are friend functions of class Book, because they need to modify book's borrow status.


### 3 Some Drawbacks
1. Only search by name is supported.
2. Too much code repeated, like search_book, search_user(when users' login or managers' add user, delete user), search_managers(when managers' login). I think it can be solved using **C++ Template**.
3. Maybe the relationship between classes can be designed more better?
