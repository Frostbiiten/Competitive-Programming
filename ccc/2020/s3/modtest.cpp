#include <iostream>

int main()
{
    int pow = 1, a = 0, b = 0, prime = 6151;

    for (int i = 1; i < 200; ++i)
    {
        a = (26 * a + i) % prime;
        b = (b + (200 - i - 1) * pow) % prime;
        pow = (pow * 26) % prime;
        std::cout << a << ' ' << b << '\n';
    }

    return 0;
}