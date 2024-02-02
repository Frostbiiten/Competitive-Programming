// https://www.acmicpc.net/problem/2562
#include <iostream>

int main()
{
    int i = 0;
    int m = -1;
    int c;

    for (int l = 0; l < 9; ++l)
    {
        std::cin >> c;
        if (c > m)
        {
            i = l;
            m = c;
        }
    }

    std::cout << m << '\n' << i + 1 << '\n';
}