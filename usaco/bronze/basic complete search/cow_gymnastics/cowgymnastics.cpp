// http://www.usaco.org/index.php?page=viewproblem2&cpid=963

#include <iostream>
#include <cstring>
#include <climits>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n, cow;
    std::cin >> k >> n;

    std::uint32_t performance[n];
    std::memset(performance, UCHAR_MAX, sizeof(performance));

    for (int i = 0; i < k; ++i)
    {
        std::uint32_t mask = 0;
        for (int j = 0; j < n; ++j)
        {
            std::cin >> cow;
            --cow; // 0-index
            performance[cow] &= mask;
            mask |= 1 << cow;
        }
    }

    int pairs = 0;
    for (int i = 0; i < n; ++i) pairs += __builtin_popcount(performance[i]);
    std::cout << pairs << '\n';

    return 0;
}