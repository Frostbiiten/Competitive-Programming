#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdint.h>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int64_t d;
    std::cin >> d;

    int64_t best = INT64_MAX;
    for (auto a = std::ceil(sqrt(d)); a > 0; --a)
    {
        int64_t b = 0;
        int64_t oldDiff = -1;

        while (true)
        {
            int64_t diff = std::abs((a * a) + (b * b) - d);
            if (diff < best)
            {
                //std::cout << a << ", " << b << '\n';
                best = diff;
            }

            if (oldDiff != -1)
            {
                if (diff > oldDiff) break;
            }

            oldDiff = diff;
            ++b;

            if (b > a) break;
        }
    }

    std::cout << best << '\n';

    return 0;
}