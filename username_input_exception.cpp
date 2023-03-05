#pragma once
#include <iostream>
#include <exception>
using namespace std;

class username_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid username!!\n";
    }
};