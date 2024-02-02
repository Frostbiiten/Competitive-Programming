// http://www.usaco.org/index.php?page=viewproblem2&cpid=736

#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    std::cin >> n >> m;

    int spotty[m];
    std::memset(spotty, 0, sizeof(spotty));

    char c;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> c;
            c -= 'A';
            spotty[j] |= 1ul << c;
        }
    }

    int plain[m];
    std::memset(plain, 0, sizeof(plain));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> c;
            c -= 'A';
            plain[j] |= 1ul << c;
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) count += (spotty[i] & plain[i]) == 0;
    std::cout << count << '\n';

    return 0;
}