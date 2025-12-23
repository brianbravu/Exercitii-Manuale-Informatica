#pragma once
#include <stdexcept>
#define SMAX 10000
using namespace std;
template <typename T>
class Stiva
{
protected:
	int vf;
	T s[SMAX];
public:
	Stiva()
	{
		vf = -1;
	}
	T& Top()
	{
		logic_error e("Stiva vida");
		if (vf < 0) throw e;
		return s[vf];
	}
	T Pop()
	{
		logic_error e("Stiva vida");
		if (vf < 0) throw e;
		return s[vf--];
	}
	void Push(const T& x)
	{
		logic_error e("Stiva plina");
		if (vf == SMAX - 1) throw e;
		s[++vf] = x;
	}
	bool Empty()
	{
		return vf == -1;
	}
	int Size()
	{
		return vf + 1;
	}
};

