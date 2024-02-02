#include <iostream>
#include <cstdint>
#include <cmath>
#include <stdint.h>
#include <climits>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int64_t d;
    std::cin >> d;

    int64_t best = INT64_MAX;
    int64_t a = std::ceil(sqrt(d));
    int64_t b = 0;

    int64_t oldDiff = INT_MAX;
    int64_t c = 0;
    while (true)
    {
        int64_t diff = (a * a) + (b * b) - d;
        if (diff > 0) --a;
        else if (diff < 0) ++b;

        diff = std::abs(diff);
        best = std::min(best, diff);
        //std::cout << diff << '\n';

        if (b > a || best == 0) break;
        if (diff > oldDiff)
        {
            // break;
            ++c;
            if (c > 10) break;
        }
        else c = 0;

        oldDiff = diff;
    }

    std::cout << best << '\n';

    return 0;
}