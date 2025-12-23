#include <iostream>

int fib(int n)
{
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}

int f(int n)
{
    if(!n) return 1;
    return 1+f(n+1);
}

int sum(int n)
{
    if(!n) return 0;
    return n%10+sum(n/10);
}

int main()
{
    std::cout << "Hello World" << std::endl;
}
