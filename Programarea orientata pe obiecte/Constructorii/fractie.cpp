#include "fractie.h"

void fractie::SetNumitor(int y)
{
	b = y;
}

void fractie::SetNumarator(int x)
{
	a = x;
}

void fractie::Simplifica()
{
	int x, y, r;
	// Calculez cmmdc cu algoritmul lui Euclid
	x = a; y = b;
	while (y)
	{
		r = x % y;
		x = y;
		y = r;
	}
	a /= x; b /= x; // Simplific
}

fractie::fractie(int x, int y)
{
	a = x; b = y;
}
