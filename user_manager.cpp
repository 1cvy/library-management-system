#pragma once
#include <iostream>
#include <iomanip> 
#include <conio.h>
#include <string>
#include <vector>
#include <regex>
#include "user.cpp"
#include "yes_or_no_input_exception.cpp"
#include "sort_all_users_input_exception.cpp"
using namespace std;

class user_manager
{
private:
	vector<user> users;
public:
	user get_user(int i)
	{
		return users.at(i);
	}
	void add_user(user user)
	{
		users.push_back(user);
	}
	int get_user_indice(string username)
	{
		for (int i = 0; i < users.size(); i++)
		{
			if (users.at(i).get_username() == username)
			{
				return i;
			}
		}
		return -1;
	}
	void edit_user(string username)
	{
		int i = get_user_indice(username);
		if (i != -1)
		{
			regex yes("(y|Y)");
			regex no("(n|N)");
			string user_input;
			search_user(username);
			cout << "Are you sure you want to edit this user?" << endl;
			cout << "[Y] Yes" << endl;
			cout << "[N] No" << endl;
			user_input = _getch();
			if (regex_match(user_input, yes))
			{
				cout << "New username: ";
				getline(cin, user_input);
				users.at(i).set_username(user_input);
				cout << "New password: ";
				getline(cin, user_input);
				users.at(i).set_password(user_input);
				cout << "New role: ";
				getline(cin, user_input);
				users.at(i).set_role(user_input);
				cout << "You have successfully edited an user!!" << endl;
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
			cout << "user not found!!" << endl;
		}
	}
	void search_user(string username)
	{

		int i = get_user_indice(username);
		if (i != -1)
		{
			cout << "Current username: " << users.at(i).get_username() << endl;
			cout << "Current password: " << users.at(i).get_password() << endl;
			cout << "Current role: " << users.at(i).get_role() << endl;
		}
		else
		{
			cout << "Book not found!!" << endl;
		}
	}
	void delete_user(string username)
	{

		int i = get_user_indice(username);
		if (i != -1)
		{
			regex yes("(y|Y)");
			regex no("(n|N)");
			string user_input;
			search_user(username);
			cout << "Are you sure you want to delete this user?" << endl;
			cout << "[Y] Yes" << endl;
			cout << "[N] No" << endl;
			user_input = _getch();
			if (regex_match(user_input, yes))
			{
				users.erase(users.begin() + i);
				cout << "You have successfully deleted this user!!" << endl;
			}
			else if (regex_match(user_input, no))
			{
				cout << "Look like you don't want to delete this user anymore!!" << endl;
			}
			else
			{
				throw yes_or_no_input_exception();
			}
		}
		else
		{
			cout << "user not found!!" << endl;
		}
	}
	void view_all_users()
	{
		//vector<book*>::iterator itr;
		cout << left << setw(8) << "#" << setw(16) << "Username" << setw(16) << "Password" << "Role" << endl;
		for (auto itr = users.begin(); itr != users.end(); itr++)
		{
			//cout << (*itr)->get_name() << endl;
			cout << left << setw(8) << itr - users.begin() + 1 << setw(16) << (*itr).get_username() << setw(16) << (*itr).get_password() << (*itr).get_role() << endl;
		}
		cout << "You have successfully viewed all users!!" << endl;
	}
	void sort_all_users(int option)
	{
		if (option == 1)
		{
			for (auto itr1 = users.begin(); itr1 != prev(users.end()); itr1++)
			{
				for (auto itr2 = users.begin(); itr2 != prev(users.end()); itr2++)
				{
					if ((*itr2) < (*next(itr2)))
					{
						iter_swap(itr2, next(itr2));
					}
				}
			}
		}
		else if (option == 2)
		{
			for (auto itr1 = users.begin(); itr1 != prev(users.end()); itr1++)
			{
				for (auto itr2 = users.begin(); itr2 != prev(users.end()); itr2++)
				{
					if ((*itr2) > (*next(itr2)))
					{
						iter_swap(itr2, next(itr2));
					}
				}
			}
		}
		else
		{
			throw sort_all_users_input_exception();
		}
	}
};