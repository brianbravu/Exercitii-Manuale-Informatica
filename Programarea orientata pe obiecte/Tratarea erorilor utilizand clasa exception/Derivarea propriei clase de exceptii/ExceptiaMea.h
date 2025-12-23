#pragma once
#include<iostream>
class ExceptiaMea:public std::logic_error
{
public:
	ExceptiaMea(const char s[]);
};

