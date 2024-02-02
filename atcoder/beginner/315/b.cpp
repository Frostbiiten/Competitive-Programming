#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int v, m, sum = 0;
    std::cin >> m;
    int d[m + 0];
    d[0] = 0;

    for (int i = 0; i < m; ++i)
    {
        std::cin >> v;
        d[i + 1] = d[i] + v;
        sum += v;
    }

    int mid = sum / 2;
    int ind = 0;
    while (d[ind] <= mid) ++ind;
    --ind;

    std::cout << ind + 1 << ' ' << mid - d[ind] + 1 << '\n';

    return 0;
}