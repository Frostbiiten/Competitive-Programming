#include <iostream>
#include <stdint.h>
#include <vector>
#include <cstring>
#include <queue>

std::pair<std::vector<int>, bool> graph[100001];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    uint32_t t1[100001];
    memset(t1, -1, sizeof(t1));

    int n, m, e, s, f;
    std::cin >> n >> m >> e >> s >> f;

    // exits
    int exit;
    for (int i = 0; i < e; ++i)
    {
        std::cin >> exit;
        graph[exit].second = true;
    }

    // guards
    int guards[s];
    for (int i = 0; i < s; ++i)
    {
        std::cin >> guards[i];
    }

    // hallways
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b;
        graph[a].first.push_back(b);
        graph[b].first.push_back(a);
    }

    // guards bfs
    for (int i = 0; i < s; ++i)
    {
        int start = guards[i];

        std::queue<int> q;
        q.push(start);
        t1[start] = 0;

        while (!q.empty())
        {
            auto current = q.front();
            q.pop();

            int nt = t1[current] + 1;
            for (auto next : graph[current].first)
            {
                // std::cout << current << " --> " << next << ' ';
                if (nt < t1[next])
                {
                    t1[next] = nt;
                    q.push(next);
                    // std::cout << " +\n";
                }
                // else std::cout << " -\n";
            }
        }
    }

    // 'player' bfs
    std::queue<int> q;
    q.push(f);
    t1[f] = 0;

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        if (graph[current].second)
        {
            std::cout << "YES\n";
            return 0;
        }

        int nt = t1[current] + 1;
        for (auto next : graph[current].first)
        {
            if (nt < t1[next])
            {
                t1[next] = nt;
                q.push(next);
            }
        }
    }

    std::cout << "NO\n";
    return 0;
}