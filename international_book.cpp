#pragma once
#include <iostream>
#include "book.cpp"
#include "book_language_input_exception.cpp"
using namespace std;

class international_book : public book
{
private:
	string language;
public:
	international_book(){}
	international_book(string name, string author, string language) : book(name, author)
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
		this->language = language;
	}
	string get_language()
	{
		return language;
	}
	void set_language(string language)
	{
		regex valid_book_language("[A-Z][a-z]+");
		if (!regex_match(language, valid_book_language))
		{
			throw book_language_input_exception();
		}
		this->language = language;
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