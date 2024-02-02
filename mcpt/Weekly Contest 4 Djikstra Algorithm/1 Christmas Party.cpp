#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdint>

// first is connection, second is cost
std::vector<std::pair<int, int>> graph[100000];
uint64_t dist[100000];
bool visited[100000];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, m;
    std::cin >> n >> m;

    int u, v, w;
    for (int i = 0; i < m; ++i)
    {
        // connection from u to v, takes w minutes
        std::cin >> u >> v >> w;
        --u; --v;

        // bidirectional?
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    memset(dist, -1, sizeof(dist));

    // priority queue with comp
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    dist[0] = 0;
    q.push({0, 0});

    // traverse
    while (!q.empty())
    {
        auto current = q.top().second;
        q.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (auto path: graph[current])
        {
            int other = path.first;
            int cost = path.second;

            int newCost = dist[current] + cost;
            if (newCost < dist[other])
            {
                dist[other] = newCost;
                q.push({newCost, other});
            }
        }
    }

    uint64_t total = 0;
    for (int i = 0; i < n; ++i) total += dist[i];
    std::cout << total << '\n';
    return 0;
}