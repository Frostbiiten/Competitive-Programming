#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, m, maxDist = 0;
    std::cin >> n >> m;

    int a, b, c, graph[n][10];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j) graph[i][j] = -1;
    }

    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b >> c;
        --a; --b;
        graph[a][b] = graph[b][a] = c;
    }

    std::function<void(bool[], int, int)> dfs = [&](bool v[], int s, int dist) -> void
    {
        v[s] = true;
        for (int conn = 0; conn < n; ++conn)
        {
            if (graph[s][conn] != -1 && !v[conn])
            {
                int newDist = dist + graph[s][conn];
                maxDist = std::max(maxDist, newDist);
                dfs(v, conn, newDist);
            }
        }
        v[s] = false;
    };

    bool v[n];
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; ++i)
    {
        dfs(v, i, 0);
    }

    std::cout << maxDist << '\n';
}