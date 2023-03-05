#pragma once
#include <iostream>
#include <exception>
using namespace std;

class invalid_option_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid option!!\n";
    }
};