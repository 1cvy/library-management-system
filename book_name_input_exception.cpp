#pragma once
#include <iostream>
#include <exception>
using namespace std;

class book_name_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid book name!!\n";
    }
};