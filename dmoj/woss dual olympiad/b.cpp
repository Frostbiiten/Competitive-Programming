#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

int events[10001];
std::pair<int, int> ranges[10001];

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    std::memset(events, -1, sizeof(events));

    int n, m, k;
    std::cin >> n >> m >> k;

    //int ranges
    // dfs end of ranges'

    // geese
    int a, b, t;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b >> t;

        ranges[i] = {a, b};
        events[t] = i;
        // might have to do t + 1 (?)
    }

    // possible positions
    std::vector<int> q;
    q.push_back(0);

    std::vector<int> toAdd;
    toAdd.reserve(2);

    // each goose attack
    for (int time = 0; time < 10001; ++time)
    {
        std::vector<int> origQ = q;

        // add l/r
        for (int i = 0; i < origQ.size(); ++i)
        {
            int left = origQ[i] - k;
            int right = origQ[i] + k;
            if (left >= 0 && !std::binary_search(q.begin(), q.end(), left))
            {
                q.insert(std::upper_bound(q.begin(), q.end(), left), left);
            }
            if (right <= n && !std::binary_search(q.begin(), q.end(), right))
            {
                q.insert(std::upper_bound(q.begin(), q.end(), right), right);
            }
        }

        // cull time ranges for each active timezone
        if (events[time] >= 0)
        {
            auto range = ranges[events[time]];

            // find first element greater than or equal to range begin
            auto wipeBegin = std::upper_bound(q.begin(), q.end(), range.first - 1);

            // find last element less than or equal to range end
            auto wipeEnd = std::lower_bound(q.begin(), q.end(), range.second + 1);
            
            // add range ends
            int beginIndex = std::distance(q.begin(), wipeBegin);
            int endIndex = std::distance(q.begin(), wipeEnd);

            toAdd.clear();

            // idk if i need abs
            if (range.first > 0 && beginIndex > 0 && std::abs(range.first - 1 - q[beginIndex - 1]) <= k) 
            {
                toAdd.push_back(range.first - 1);
            }

            if (range.second < n && endIndex < q.size() - 1 && std::abs(q[endIndex + 1] - (range.second + 1)) <= k) 
            {
                toAdd.push_back(range.second + 1);
            }

            // erase range
            q.erase(wipeBegin, wipeEnd);
            q.insert(toAdd.begin(), toAdd.end(), wipeEnd);
        }

        // exit if dead
        if (q.empty())
        {
            std::cout << "NO\n";
            return 0;
        }
    }

    std::cout << "YES\n";
    return 0;
}