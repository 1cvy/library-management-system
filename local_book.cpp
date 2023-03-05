#pragma once
#include <iostream>
#include <regex>
#include <conio.h>
#include "book.cpp"
#include "yes_or_no_input_exception.cpp"
#include "book_language_input_exception.cpp"
using namespace std;

class local_book : public book
{
private:
	static string local_language;
public:
	local_book(){}
	local_book(string name, string author, string language) : book (name,author)
	{
		regex valid_book_name("([A-Z]+[a-z]*( [A-Z]+[a-z]*)*)");
		if (!regex_match(name, valid_book_name))
		{
			throw book_name_input_exception();
		}
		regex valid_book_author("[A-Z][a-z]+ [A-Z][a-z]+");
		if (!regex_match(author, valid_book_author))
		{
			throw book_author_input_exception();
		}
		regex valid_book_language("[A-Z][a-z]+");
		if (!regex_match(language, valid_book_language))
		{
			throw book_language_input_exception();
		}
		cout << "Current local book language: " << local_language << endl;
		cout << "New local book language: " << language << endl;
		cout << "Are you sure you want to change local book language?" << endl;
		cout << "[Y] Yes" << endl;
		cout << "[N] No" << endl;
		string user_input;
		user_input = _getch();
		regex yes("(y|Y)");
		regex no("(n|N)");
		if (regex_match(user_input, yes))
		{
			this->local_language = language;
			cout << "You have successfully changed the local book language!!" << endl;
		}
		else if (regex_match(user_input, no))
		{
			cout << "Look like you don't want to change local book language anymore!!" << endl;
		}
		else
		{
			throw yes_or_no_input_exception();
		}
	}
	~local_book()
	{

	}
	string get_language()
	{
		return local_language;
	}
	void set_language(string language)
	{
		regex valid_book_language("[A-Z][a-z]+");
		if (!regex_match(language, valid_book_language))
		{
			throw book_language_input_exception();
		}
		cout << "Current local book language: " << local_language << endl;
		cout << "New local book language: " << language << endl;
		cout << "Are you sure you want to change local book language?" << endl;
		cout << "[Y] Yes" << endl;
		cout << "[N] No" << endl;
		string user_input;
		user_input = _getch();
		regex yes("(y|Y)");
		regex no("(n|N)");
		if (regex_match(user_input, yes))
		{
			this->local_language = language;
			cout << "You have successfully changed the local book language!!" << endl;
		}
		else if (regex_match(user_input, no))
		{
			cout << "Look like you don't want to change local book language anymore!!" << endl;
		}
		else
		{
			throw yes_or_no_input_exception();
		}
	}
	bool operator < (book* book)
	{
		int final_length;
		if (get_name().length() < book->get_name().length())
		{
			final_length = get_name().length();
		}
		else
		{
			final_length = book->get_name().length();
		}
		for (int i = 0; i < final_length; i++)
		{
			if (get_name()[i] == book->get_name()[i])
			{
				continue;
			}
			else if (get_name()[i] < book->get_name()[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
	bool operator > (book* book)
	{
		int final_length;
		if (get_name().length() < book->get_name().length())
		{
			final_length = get_name().length();
		}
		else
		{
			final_length = book->get_name().length();
		}
		for (int i = 0; i < final_length; i++)
		{
			if (get_name()[i] == book->get_name()[i])
			{
				continue;
			}
			else if (get_name()[i] > book->get_name()[i])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		return false;
	}
};