#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <queue>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, m, gnomes;
    std::cin >> n >> m;

    int p[n], gp = INT_MAX;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> p[i];
        gp = std::min(gp, p[i]);
    }

    bool v[10000];
    for (int i = 0; i < m; ++i)
    {
        std::cin >> gnomes;
        std::queue<std::pair<int, int>> q;
        memset(v, 0, sizeof(v));
        q.push({gnomes, 0});
        int sol = -1;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            if (!cur.first)
            {
                sol = cur.second;
                break;
            }

            for (int j = 0; j < n; ++j)
            {
                int next = (cur.first / p[j]) * p[j];
                if (next != cur.first && !v[next])
                {
                    q.push({next, cur.second + 1});
                    v[next] = true;
                }
            }
        }

        std::cout << sol << ' ';
    }

    std::cout << '\n';
    return 0;
}