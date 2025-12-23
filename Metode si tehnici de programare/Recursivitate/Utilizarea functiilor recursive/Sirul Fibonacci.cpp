#include <iostream>

unsigned long fib(int x)
{
    if (x <= 1) return 1;
    return fib(x - 2) + fib(x - 1);
}

int main()
{
    std::cout << "Hello World!\n";
}
