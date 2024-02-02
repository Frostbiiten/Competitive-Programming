#include <iostream>
#include <numeric>

int main()
{
    int numerator, denominator;
    std::cin >> numerator >> denominator;

    int whole = numerator / denominator;

    if (whole != 0)
    {
        std::cout << whole;
    }

    if (numerator % denominator != 0)
    {
        if (whole != 0)
        {
            std::cout << ' ';
        }

        numerator -= denominator * whole;
        int gcd = std::gcd(numerator, denominator);
        std::cout << numerator / gcd << '/' << denominator / gcd;
    }

    std::cout << '\n';
    return 0;
}