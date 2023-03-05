#pragma once
#include <iostream>
#include <regex>
#include "book_name_input_exception.cpp"
#include "book_author_input_exception.cpp"
using namespace std;

class book
{
private:
	string name;
	string author;
public:
	book(){}
	book(string name, string author)
	{
		this->name = name;
		this->author = author;
	}
	~book(){}
	string get_name()
	{
		return name;
	}
	string get_author()
	{
		return author;
	}
	virtual string get_language() = 0;
	void set_name(string name)
	{
		regex valid_book_name("([A-Z]+[a-z]*( [A-Z]+[a-z]*)*)");
		if (!regex_match(name, valid_book_name))
		{
			throw book_name_input_exception();
		}
		this->name = name;
	}
	void set_author(string author)
	{
		regex valid_book_author("[A-Z][a-z]+ [A-Z][a-z]+");
		if (!regex_match(author, valid_book_author))
		{
			throw book_author_input_exception();
		}
		this->author = author;
	}
	virtual void set_language(string language) = 0;
	virtual bool operator < (book* book) = 0;
	virtual bool operator > (book* book) = 0;
};