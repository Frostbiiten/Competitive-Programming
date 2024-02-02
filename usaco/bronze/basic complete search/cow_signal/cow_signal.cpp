// http://www.usaco.org/index.php?page=viewproblem2&cpid=665
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    std::cin >> m >> n >> k;

    std::string rows[m];

    for (int i = 0; i < m; ++i) std::cin >> rows[i];

    int h = m * k, w = n * k;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j) std::cout << rows[i / k][j / k];
        std::cout << '\n';
    }

    return 0;
}