// TLE :(
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, m, s;
    std::cin >> n >> m;

    int x[n];
    memset(x, -1, sizeof(x));

    std::vector<std::vector<int>> graph;
    graph.resize(n);

    {
        int a[m];
        for (int i = 0; i < m; ++i)
        {
            std::cin >> a[i];
            --a[i];
        }
        for (int i = 0; i < m; ++i)
        {
            std::cin >> s;
            --s;
            graph[s].push_back(a[i]);
            graph[a[i]].push_back(s);
        }
    }

    int last = 0;

    while (true) // ***
    {
        bool exit = false;
        std::queue<int> q;

        for (int i = last; i < n; ++i)
        {
            if (x[i] == -1)
            {
                x[i] = 0;
                q.push(i);
                last = i + 1;
                break;
            }

            if (i == n - 1)
            {
                exit = true;
            }
        }

        if (exit) break;

        while (q.size())
        {
            auto node = q.front();
            int val = x[node];

            for (auto neighbor : graph[node])
            {
                if (x[neighbor] == -1)
                {
                    x[neighbor] = !val;
                    q.push(neighbor);
                }
                else if (x[neighbor] == val)
                {
                    std::cout << "No\n";
                    return 0;
                }
            }

            q.pop();
        }
    }

    std::cout << "Yes\n";
}