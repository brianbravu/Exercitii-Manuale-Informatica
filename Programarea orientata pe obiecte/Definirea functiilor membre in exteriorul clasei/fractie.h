#pragma once
class fractie
{
private:
	int a; // Numarator
	int b; // Numitor
public:
	int GetNumarator()
	{
		return a;
	}
	int GetNumitor()
	{
		return b;
	}
	void SetNumitor(int y);
	void SetNumarator(int x);
	void Simplifica();
};