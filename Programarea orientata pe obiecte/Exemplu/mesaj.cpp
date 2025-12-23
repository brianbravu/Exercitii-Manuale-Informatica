#include "mesaj.h"

mesaj::mesaj()
{
	lg = 0;
	sir = nullptr;
}

mesaj::mesaj(const char s[])
{
	int i;
	lg = strlen(s); // Determin lungimea sirului
	sir = new char[lg];
	// Aloc dinamic memorie pentru vectorul care retine
	// caracterele mesajului
	for (i = 0; i < lg; i++) sir[i] = s[i];
	// Copiez caracterele mesajului
}

int mesaj::GetLg()
{
	return lg;
}

void mesaj::Scrie()
{
	if (sir)
		for (int i = 0; i < lg; i++) std::cout << sir[i];
	else
		std::cout << "Mesajul este vid!";
	std::cout << '\n';
}
