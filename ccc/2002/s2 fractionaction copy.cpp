#include <iostream>
#include <numeric>

int gcd(int numerator, int denominator)
{

    for (int div = numerator; div > 1; --div)
    {
        if (numerator % div == 0 || denominator % div == 0)
        {
            
        }
    }
}

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
        std::cout << numerator / gcd << '/' << denominator / gcd;
    }

    std::cout << '\n';
    return 0;
}