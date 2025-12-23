#include <iostream>

unsigned long P(int n)
{
    long S = 0;
    int k;
    if (n <= 2) return 1;
    for (k = 1; k < n; k++) S += P(k) * P(n - k);
    return S;
}

int main()
{
    std::cout << "Hello World!\n";
}
