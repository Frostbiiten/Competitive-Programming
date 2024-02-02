#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>

std::vector<int> factors2[1000000000];

int main()
{
    //std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    for (int i = 1002; i > 0; --i)
    {
        for (int j = 0; j < 1002; j += i)
        {
            factors2[j].push_back(i);
        }
    }

    std::vector<int> path; path.reserve(1001);
    int visited[1002];
    memset(visited, 0, sizeof(visited));

    std::function<bool(int, int)> dfs = [&](int s, int d) -> bool
    {
        if (s == 1)
        {
            path.push_back(1);
            return true;
        }

        bool found = false;

        for (int i : factors2[s])
        {
            if (s != i && visited[i] < 2)
            {
                std::cout << std::string(d, ' ') << i << " is a factor of " << s << ", exploring " << s - i << '\n';

                ++visited[i];
                bool result = dfs(s - i, d + 1);
                --visited[i];

                found = result || found;
                if (found)
                {
                    path.push_back(s);
                    break;
                }
            }
        }

        return found;
    };

    int t, k;
    //std::cin >> t;
    t = 1000;
    for (int test = 0; test < t; ++test)
    {
        //std::cin >> k;
        k = 227;
        path.clear();
        dfs(k, 0);

        for (int i = path.size() - 1; i >= 0; --i) std::cout << path[i] << ' ';
        std::cout << '\n';
    }

    return 0;
}