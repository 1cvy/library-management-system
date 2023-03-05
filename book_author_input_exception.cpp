#pragma once
#include <iostream>
#include <exception>
using namespace std;

class book_author_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid book author!!\n";
    }
};