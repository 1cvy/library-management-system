#pragma once
#include <iostream>
#include <exception>
using namespace std;

class sort_all_books_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid sort option!!\n";
    }
};