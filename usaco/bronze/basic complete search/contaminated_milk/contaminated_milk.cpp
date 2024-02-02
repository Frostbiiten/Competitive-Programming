// http://www.usaco.org/index.php?page=viewproblem2&cpid=569
// was having some problems, then realized i used __builtin_popcount and not __builtin_popcountll
// for some reason, I always make mistakes when working with largger integer types

#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    freopen("badmilk.in", "r", stdin);
    freopen("badmilk.out", "w", stdout);

    int n, m, d, s;
    std::cin >> n >> m >> d >> s;
    
    std::uint64_t record[n][100];
    std::uint64_t drinkers[m];

    for (int i = 0; i < n; ++i) memset(record[i], 0, sizeof(record[i]));
    memset(drinkers, 0, sizeof(drinkers));

    int p, m2, t;
    for (int i = 0; i < d; ++i)
    {
        std::cin >> p >> m2 >> t; --p; --m2; --t;
        record[p][t] |= 1ull << m2;
        drinkers[m2] |= 1ull << p;
    }

    std::uint64_t milkMask = 0, currentMask;

    // scan first for initial mask
    std::cin >> p >> t; --p; --t;

    // "strictly earlier" 
    for (int j = 0; j < t; ++j) milkMask |= record[p][j];

    for (int i = 1; i < s; ++i)
    {
        std::cin >> p >> t; --p; --t;

        currentMask = 0;
        for (int j = 0; j < t; ++j) currentMask |= record[p][j];
        milkMask &= currentMask;
    }

    for (int i = 0; i < 50; ++i)
    {
        if (milkMask & 1)
        {
            std::cout << __builtin_popcountll(drinkers[i]);
            break;
        }
        milkMask >>= 1;
    }

    return 0;
}