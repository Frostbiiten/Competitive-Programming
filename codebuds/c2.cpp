#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, m, in, gnomes;
    std::cin >> n >> m;

    std::set<int> p;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        p.insert(in);
    }
    int gp = *p.rbegin();

    std::uint32_t count[10001];
    std::memset(count, UCHAR_MAX, sizeof(count));
    int oi = std::min(gp, 10000);
    std::fill_n(count, oi, 1);
 
    for (int i = oi; i < 10001; ++i)
    {
        if (i == 10000) break;
        for (int prime : p)
        {
            int rnd = (i / prime) * prime;
            if (rnd != i && count[rnd] != UINT_MAX) count[i] = std::min(count[i], count[rnd] + 1);
        }
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> gnomes;
        std::int64_t sol = count[gnomes];
        if (sol == UINT_MAX) sol = -1;
        std::cout << sol << ' ';
    }
    std::cout << '\n';

    return 0;
}