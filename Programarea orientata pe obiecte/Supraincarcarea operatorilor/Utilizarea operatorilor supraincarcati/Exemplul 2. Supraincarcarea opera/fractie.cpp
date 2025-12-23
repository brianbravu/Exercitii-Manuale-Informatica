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
	// Calculez cmmdc cu ajutorul lui Euclid
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
	a = x;
	b = y;
}

fractie& fractie::operator++() // Forma prefixata
{
	// TODO: insert return statement here
	a += b;
	return *this;
}

fractie fractie::operator++(int fictiv) // Forma postfixata
{
	fractie temp(a, b);
	++(*this);
	return temp;
}

fractie& fractie::operator--() // Forma prefixata
{
	// TODO: insert return statement here
	a -= b;
	return *this;
}

fractie fractie::operator--(int fictiv) // Forma postixata
{
	fractie temp(a, b);
	--(*this);
	return temp;
}

fractie::operator double() const
{
	return (double)a / b;
}

fractie operator-(const fractie& f)
{
	fractie temp(-f.a, f.b);
	return temp;
}

fractie operator+(const fractie& f1, const fractie& f2)
{
	fractie rez;
	rez.a = f1.a * f2.b + f1.b * f2.a;
	rez.b = f1.b * f2.b;
	rez.Simplifica();
	return rez;
}

fractie operator-(const fractie& f1, const fractie& f2)
{
	fractie rez;
	rez.a = f1.a * f2.b - f1.b * f2.a;
	rez.b = f1.b * f2.b;
	rez.Simplifica();
	return rez;
}

fractie operator*(const fractie& f1, const fractie& f2)
{
	fractie rez;
	rez.a = f1.a * f2.a;
	rez.b = f1.b * f2.b;
	rez.Simplifica();
	return rez;
}

fractie operator/(const fractie& f1, const fractie& f2)
{
	fractie rez;
	rez.a = f1.a * f2.b;
	rez.b = f1.b * f2.a;
	rez.Simplifica();
	return rez;
}

fractie& operator+=(fractie& f1, const fractie& f2)
{
	// TODO: insert return statement here
	f1.a = f1.a * f2.b + f1.b * f2.a;
	f1.b = f1.b * f2.b;
	f1.Simplifica();
	return f1;
}

fractie& operator-=(fractie& f1, const fractie& f2)
{
	// TODO: insert return statement here
	f1.a = f1.a * f2.b - f1.b * f2.a;
	f1.b = f1.b * f2.b;
	f1.Simplifica();
	return f1;
}

fractie& operator*=(fractie& f1, const fractie& f2)
{
	// TODO: insert return statement here
	f1.a = f1.a * f2.a;
	f1.b = f1.b * f2.b;
	f1.Simplifica();
	return f1;
}

fractie& operator/=(fractie& f1, const fractie& f2)
{
	// TODO: insert return statement here
	f1.a = f1.a * f2.b;
	f1.b = f1.b * f2.a;
	f1.Simplifica();
	return f1;
}

bool operator==(const fractie& f1, const fractie& f2)
{
	return f1.a * f2.b - f1.b * f2.a == 0;
}

bool operator!=(const fractie& f1, const fractie& f2)
{
	return f1.a * f2.b - f1.b * f2.a;
}

bool operator<(const fractie& f1, const fractie& f2)
{
	return f1.a * f2.b < f1.b * f2.a;
}

bool operator>(const fractie& f1, const fractie& f2)
{
	return f2 < f1;
}

bool operator<=(const fractie& f1, const fractie& f2)
{
	return !(f1 > f2);
}

bool operator>=(const fractie& f1, const fractie& f2)
{
	return !(f1 < f2);
}

istream& operator<<(istream& in, fractie& f)
{
	// TODO: insert return statement here
	in >> f.a >> f.b;
	return in;
}

ostream& operator>>(ostream& out, const fractie& f)
{
	// TODO: insert return statement here
	out << f.a << '/' << f.b;
	return out;
}
