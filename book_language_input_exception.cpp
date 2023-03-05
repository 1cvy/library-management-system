#pragma once
#include <iostream>
#include <exception>
using namespace std;

class book_language_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid book language!!\n";
    }
};