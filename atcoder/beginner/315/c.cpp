#include <iostream>
#include <algorithm>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, f, s;
    std::cin >> n;

    int maxF = 0;

    int best[n][2];
    for (int i = 0; i < n; ++i) memset(best[i], 0, sizeof(best[i]));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> f >> s;
        --f; // 0-index
        maxF = std::max(maxF, f);
        if (s >= best[f][0])
        {
            best[f][1] = best[f][0];
            best[f][0] = s;
        }
    }

    int highest = 0, same, diff;
    for (int i = 0; i <= maxF; ++i)
    {
        same = best[i][0] + (best[i][1] >> 1);
        highest = std::max(highest, same);

        for (int j = 0; j < i; ++j)
        {
            diff = best[i][0] + best[j][0];
            highest = std::max(highest, diff);
        }
    }

    std::cout << highest << '\n';
    return 0;
}