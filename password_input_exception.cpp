#pragma once
#include <iostream>
#include <exception>
using namespace std;

class password_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid password!!\n";
    }
};