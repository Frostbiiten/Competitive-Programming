#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    std::int64_t n, sum = 0;
    std::cin >> n;
    std::int64_t a[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        sum += a[i];
    }

    std::int64_t dist = 0;
    std::int64_t minconv = sum / n;
    std::int64_t maxconv = (sum + n - 1) / n;
    std::int64_t mincount = n - sum % n;

    std::sort(a, a + n);

    for (int i = 0; i < n; ++i)
    {
        if (mincount)
        {
            dist += std::abs(minconv - a[i]);
            --mincount;
        }
        else
        {
            dist += std::abs(maxconv - a[i]);
        }
    }

    std::cout << (dist >> 1) << '\n';
}