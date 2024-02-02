// http://www.usaco.org/index.php?page=viewproblem2&cpid=1011
#include <iostream>
#include <cstring>

typedef std::pair<int, int> interval;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    std::cin >> n;

    interval shifts[n];
    int timeline[1000];
    std::memset(timeline, 0, sizeof(timeline));

    int coveredTime = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> shifts[i].first >> shifts[i].second;
        
        for (int j = shifts[i].first; j < shifts[i].second; ++j)
        {
            coveredTime += (timeline[j] == 0);
            ++timeline[j];
        }
    }

    int minLostTime = 1000;
    for (int i = 0; i < n; ++i)
    {
        interval shift = shifts[i];

        int lostTime = 0;
        for (int j = shift.first; j < shift.second; ++j) lostTime += (timeline[j] == 1);
        minLostTime = std::min(minLostTime, lostTime);
    }

    std::cout << coveredTime - minLostTime << '\n';
    return 0;
}