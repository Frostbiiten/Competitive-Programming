#include <ios>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, m, l, t;
    std::cin >> n >> m;

    int best = -1, sum;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> l >> t;
        sum = l + t;
        if (sum <= n) best = std::max(best, l);
    }

    if (best == -1) std::cout << "-1\n";
    else std::cout << best << '\n';

    return 0;
}