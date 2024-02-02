#include <iostream>
#include <cmath>
#include <stdint.h>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    uint64_t b;
    std::cin >> b;

    for (uint64_t i = 1; i <= 16; ++i)
    {
        uint64_t v = powl(i, i);

        if (b == v)
        {
            std::cout << i << '\n';
            return 0;
        }
    }

    std::cout << "-1\n";
}