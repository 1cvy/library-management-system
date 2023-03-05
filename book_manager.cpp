#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <conio.h>
#include <iomanip> 
#include <algorithm>
#include <fstream>
#include "book.cpp"
#include "book_name_input_exception.cpp"
#include "yes_or_no_input_exception.cpp"
#include "book_language_input_exception.cpp"
#include "book_author_input_exception.cpp"
#include "sort_all_books_input_exception.cpp"
#include "local_book.cpp"
#include "international_book.cpp"
using namespace std;

class book_manager
{
private:
	vector<book*> books;
public:
	void add_book(book* book)
	{
		books.push_back(book);
		cout << "You have successfully added a book!!" << endl;
	}
	int get_book_indice(string name)
	{
		for (int i = 0; i < books.size(); i++)
		{
			if (books.at(i)->get_name() == name)
			{
				return i;
			}
		}
		return -1;
	}
	void edit_book(string name)
	{
		int i = get_book_indice(name);
		if (i != -1)
		{
			regex yes ("(y|Y)");
			regex no ("(n|N)");
			string user_input;
			search_book(name);
			cout << "Are you sure you want to edit this book?" << endl;
			cout << "[Y] Yes" << endl;
			cout << "[N] No" << endl;
			user_input = _getch();
			if (regex_match(user_input, yes))
			{
				cout << "New book name: ";
				getline(cin, user_input);
				books.at(i)->set_name(user_input);
				cout << "New book author: ";
				getline(cin, user_input);
				books.at(i)->set_author(user_input);
				cout << "New book language: ";
				getline(cin, user_input);
				books.at(i)->set_language(user_input);
				cout << "You have successfully edited a book!!" << endl;
			}
			else if (regex_match(user_input, no))
			{
				cout << "Look like you don't want to edit this book anymore!!" << endl;
			}
			else
			{
				throw yes_or_no_input_exception();
			}
		}
		else
		{
			cout << "Book not found!!" << endl;
		}
	}
	void search_book(string name)
	{
		int i = get_book_indice(name);
		if (i != -1)
		{
			cout << "Current book name: " << books.at(i)->get_name() << endl;
			cout << "Current book author: " << books.at(i)->get_author() << endl;
			cout << "Current book language: " << books.at(i)->get_language() << endl;
		}
		else
		{
			cout << "Book not found!!" << endl;
		}
	}
	void delete_book(string name)
	{
		int i = get_book_indice(name);
		if (i != -1)
		{
			regex yes("(y|Y)");
			regex no("(n|N)");
			string user_input;
			search_book(name);
			cout << "Are you sure you want to delete this book?" << endl;
			cout << "[Y] Yes" << endl;
			cout << "[N] No" << endl;
			user_input = _getch();
			if (regex_match(user_input, yes))
			{
				books.erase(books.begin() + i);
				cout << "You have successfully deleted this book!!" << endl;
			}
			else if (regex_match(user_input, no))
			{
				cout << "Look like you don't want to delete this book anymore!!" << endl;
			}
			else
			{
				throw yes_or_no_input_exception();
			}
		}
		else
		{
			cout << "Book not found!!" << endl;
		}
	}
	void view_all_books()
	{
		//vector<book*>::iterator itr;
		cout << left << setw(8) << "#" << setw(16) << "Name" << setw(16) << "Author" << "Language"<<endl;
		for (auto itr = books.begin(); itr != books.end(); itr++)
		{
			//cout << (*itr)->get_name() << endl;
			cout << left << setw(8) << itr - books.begin() + 1 << setw(16) << (*itr)->get_name() << setw(16) << (*itr)->get_author() << (*itr)->get_language() << endl;
		}
		cout << "You have successfully viewed all books!!" << endl;
	}
	void sort_all_books(int option)
	{
		if (option == 1)
		{
			for (auto itr1 = books.begin(); itr1 != prev(books.end()); itr1++)
			{
				for (auto itr2 = books.begin(); itr2 != prev(books.end()); itr2++)
				{
					if ((*itr2)->get_name() > (*next(itr2))->get_name())
					{
						iter_swap(itr2, next(itr2));
					}
				}
			}
		}
		else if (option == 2)
		{
			for (auto itr1 = books.begin(); itr1 != prev(books.end()); itr1++)
			{
				for (auto itr2 = books.begin(); itr2 != prev(books.end()); itr2++)
				{
					if ((*itr2)->get_name() < (*next(itr2))->get_name())
					{
						iter_swap(itr2, next(itr2));
					}
				}
			}
		}
		else
		{
			throw sort_all_books_input_exception();
		}
	}
	void save_all_books_to_file() 
	{
		
	}
	void load_all_books_from_file() 
	{
		
	}
};