// http://www.usaco.org/index.php?page=viewproblem2&cpid=736
// an attempt to increase memory locality
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;

    std::uint64_t mask[m];
    std::memset(mask, 0, sizeof(mask));

    char c;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> c;
            c -= 'A';
            mask[j] |= 1ull << c;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> c;
            c -= 'A';
            mask[j] |= 1ull << (c + 32);
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) count += (mask[i] & (mask[i] >> 32)) == 0;
    std::cout << count << '\n';

    return 0;
}