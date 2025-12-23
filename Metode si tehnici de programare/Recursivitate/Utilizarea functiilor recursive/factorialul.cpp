#include <iostream>

unsigned long fact(int n)
{
    if (!n) return 1;
    return n * fact(n - 1);
}

int main()
{
    std::cout << "Hello World!\n";
}
