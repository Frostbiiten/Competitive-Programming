#include <algorithm>
#include <iostream>
#include <stdint.h>
#include <vector>

int p[1000001];

int main()
{
    for (int step = 2; step < 1000; ++step)
    {
        if (p[step]) continue;
        for (int i = step * step; i < 1000001; i += step) p[i] = 1;
    }

    p[0] = false;
    for (int i = 1; i < 1000001; ++i) p[i] = p[i - 1] + !((bool)p[i]);

    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t, n, m;
    std::cin >> t;

    while (t--)
    {
        std::cin >> n >> m;
        n = std::max(n, 3);
        m = std::max(n - 1, m);
        std::cout << p[m] - p[n - 1] << '\n';
    }
}