#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n;
    std::cin >> n;
    int en = 0, on = 0;
    std::uint64_t inc = 0;
    int a[n], e[n], o[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        if (a[i] & 1)
        {
            inc += (a[i] - 1) >> 1;
            o[on] = i;
            ++on;
        }
        else
        {
            e[en] = i;
            ++en;
        }
    }

    if (on >= 1)
    {
        for (int i = 0; i < en; ++i) inc += (a[e[i]] - 1) >> 1;
    }
    else
    {
        for (int i = 0; i < en; ++i) inc += a[e[i]] >> 1;
    }

    std::cout << inc << '\n';
    for (int i = 0; i < 1 && i < on; ++i) std::cout << o[i] + 1 << ' ';
    for (int i = 0; i < en; ++i) std::cout << e[i] + 1 << ' ';
    for (int i = 1; i < on; ++i) std::cout << o[i] + 1 << ' ';

    return 0;
}