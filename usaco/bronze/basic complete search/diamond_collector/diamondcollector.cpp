// http://www.usaco.org/index.php?page=viewproblem2&cpid=639

#include <algorithm>
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    std::cin >> n >> k;

    int diamonds[n];
    for (int i = 0; i < n; ++i) std::cin >> diamonds[i];
    std::sort(diamonds, diamonds + n);

    int max = 0;
    for (int begin = 0; begin < n; ++begin)
    {
        for (int end = begin + 1; end < n; ++end)
        {
            int diff = diamonds[end] - diamonds[begin];
            if (diff > k) break;
            else max = std::max(max, end - begin);
        }
    }

    std::cout << max + 1 << '\n';
    return 0;
}