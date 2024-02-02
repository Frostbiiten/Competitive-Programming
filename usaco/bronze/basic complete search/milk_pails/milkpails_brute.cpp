// http://www.usaco.org/index.php?page=viewproblem2&cpid=615

#include <iostream>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    std::cin >> x >> y >> m;

    int width = m / x;
    int height = m / y;

    int max = y;
    for (int i = 0; i <= width; ++i)
    {
        for (int j = 0; j <= height; ++j)
        {
            int sum = i * x + j * y;
            if (sum <= m && sum > max) max = sum;
        }
    }

    std::cout << max << '\n';
    return 0;
}