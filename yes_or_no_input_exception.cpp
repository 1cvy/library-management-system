#pragma once
#include <iostream>
#include <exception>
using namespace std;

class yes_or_no_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid option!!\n";
    }
};