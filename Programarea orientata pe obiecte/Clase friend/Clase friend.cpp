// Clase friend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class B;

class A
{
private:
    int y;
public:
    A(int b = 0)
    {
        y = b;
    }
    void Suma(B& ob);
};

class B
{
private:
    int x;
public:
    int Getx()
    {
        return x;
    }
    void Setx(int a)
    {
        x = a;
    }
    friend class A;
};

void A::Suma(B& ob)
{
    ob.x += y;
}

int main()
{
    A a(10);
    B b;
    b.Setx(7);
    a.Suma(b);
    cout << b.Getx();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
