#pragma once
#include <iostream>
#include <regex>
#include "username_input_exception.cpp"
#include "password_input_exception.cpp"
#include "role_input_exception.cpp"
using namespace std;

class user
{
private:
	string username;
	string password;
	string role;
public:
	string get_username()
	{
		return username;
	}
	string get_password()
	{
		return password;
	}
	string get_role()
	{
		return role;
	}
	void set_username(string username)
	{
		regex valid_username("[A-Za-z0-9]+");
		if (!regex_match(username, valid_username))
		{
			throw username_input_exception();
		}
		this->username = username;
	}
	void set_password(string password)
	{
		regex valid_password("[A-Za-z0-9]+");
		if (!regex_match(password, valid_password))
		{
			throw password_input_exception();
		}
		this->password = password;
	}
	void set_role(string role)
	{
		regex valid_role("(Admin|Librarian)");
		if (!regex_match(role, valid_role))
		{
			throw role_input_exception();
		}
		this->role = role;
	}
	bool operator < (user user)
	{
		if (role=="Librarian" && user.get_role()=="Admin")
		{
			return true;
		}
		return false;
	}
	bool operator > (user user)
	{
		if (role == "Admin" && user.get_role() == "Librarian")
		{
			return true;
		}
		return false;
	}
};