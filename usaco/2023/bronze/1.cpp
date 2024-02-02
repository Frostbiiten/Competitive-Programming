#include <iostream>
#include <algorithm>
#include <stdint.h>

int64_t cows[200001];
int64_t canes[200001];
int64_t cpsa[200001];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, m;
    std::cin >> n >> m;

    // cow heights
    for (int i = 0; i < n; ++i) std::cin >> cows[i];

    // candy cane heights
    for (int i = 0; i < m; ++i) std::cin >> canes[i];

    // cane order is irrelevant, so sort (min to greatest)
    std::sort(canes, canes + m);

    cpsa[0] = 0;
    for (int i = 0; i < m; ++i) cpsa[i + 1] = cpsa[i] + canes[i];

    int64_t eatenHeight = 0;
    int64_t cowBound = 0;

    // for each cow
    for (int i = 0; i < n; ++i)
    {
        // none will be eaten...
        if (cowBound >= cows[i]) continue;

        int64_t heightGained = 0;

        // find first cane larger than cow
        auto iter = std::upper_bound(canes, canes + m, cows[i]);
        auto index = iter - std::begin(canes);

        // all greater than or equal to height
        heightGained += (m - index) * (cows[i] - cowBound);

        // new psa: from first index greater than minheight to index - 1, then subtract eatenHeight * (end-begin)

        auto iter2 = std::upper_bound(canes, canes + m, cowBound);
        auto index2 = iter2 - std::begin(canes);
        
        int64_t v = cpsa[index] - cpsa[index2];
        if (index >= index2) v -= (index - index2) * cowBound;
        heightGained += v;

        if (index > 0 && canes[index - 1] > eatenHeight) eatenHeight = canes[index - 1];
        if (cows[i] > cowBound) cowBound = cows[i];
        cows[i] += heightGained;
    }

    for (int i = 0; i < n; ++i) std::cout << cows[i] << '\n';

    return 0;
}