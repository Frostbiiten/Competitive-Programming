// https://www.acmicpc.net/problem/2739
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    for (int i = 1; i <= 9; ++i)
    {
        std::cout << n << " * " << i << " = " << n * i << '\n';
    }

    return 0;
}