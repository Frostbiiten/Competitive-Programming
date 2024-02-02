#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, f, s;
    std::cin >> n;

    int best[n];
    memset(best, 0, sizeof(best));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> f >> s;
        --f; // 0-index
        best[f] = std::max(best[f], s);
    }

    int highest = 0;
    for (int i = 0; i < n; ++i)
    {
        if(best[i] == 0) continue;
        highest = std::max(highest, best[i] + best[i] >> 1);

        for (int j = 0; j < n; ++j)
        {
            if (best[j] == 0 || best[i] < best[j]) continue;
            highest = std::max(highest, best[i] + best[j]);
        }
    }
    std::cout << highest << '\n';

    return 0;
}