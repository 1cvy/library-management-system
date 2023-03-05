#pragma once
#include <iostream>
#include <exception>
using namespace std;

class role_input_exception : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "invalid role!!\n";
    }
};