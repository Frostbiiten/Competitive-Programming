#include <iostream>
#include <cstdint>
#include <climits>
#include <map>

int main()
{
    //std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t;
    std::cin >> t;

    int n, m, k;
    while (t--)
    {
        std::cin >> n >> m >> k;
        int a[n], b[m];

        bool curr = false;
        int min[2] = {INT_MAX, INT_MAX};
        int max[2] = {-1, -1};

        std::uint64_t sumA = 0;
        std::uint64_t sumB = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            sumA += a[i];
            max[0] = std::max(max[0], a[i]);
            min[0] = std::min(min[0], a[i]);
        }

        for (int i = 0; i < m; ++i)
        {
            std::cin >> b[i];
            sumB += b[i];
            max[1] = std::max(max[1], b[i]);
            min[1] = std::min(min[1], b[i]);
        }

        std::map<std::pair<int, int>, int> history;

        bool whichMax = max[0] < max[1];
        bool whichMin = min[0] > min[1];

        int time = 0;
        while (time < k)
        {
            if (time == 0 && min[curr] > max[!curr])
            {
                curr = !curr;
                ++time;
                continue;
            }

            std::pair<int, int> p = {min[curr], max[!curr]};

            int thisMin = min[curr];
            int thatMax = max[!curr];
            int delta = thatMax - thisMin;
            std::swap(min[curr], max[!curr]);
            if (curr)
            {
                sumA += delta;
                sumB -= delta;
            }
            else
            {
                sumB += delta;
                sumA -= delta;
            }


            // check history
            auto search = history.find(p);
            if (search != history.end())
            {
                // repeat
                int delta = time - search->second;
                int skip = ((k - time) / delta) * delta;
                history[p] = time;
                if (skip)
                {
                    if (skip & 1) curr = !curr;
                    time += skip;
                    continue;
                }
            }

            // if no continue
            ++time;
            history[p] = time;
            curr = !curr;
        }

        std::cout << sumA << '\n';
    }

    return 0;
}
