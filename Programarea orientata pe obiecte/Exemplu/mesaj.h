#pragma once
#include <iostream>
class mesaj
{
private:
	char* sir;
	int lg;
public:
	mesaj(); // Constructor fara parametri
	mesaj(const char s[]); // Constructor supraincarcat
	int GetLg();
	void Scrie();
};

