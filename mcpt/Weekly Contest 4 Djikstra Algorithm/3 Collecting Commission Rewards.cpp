#include <iostream>
#include <stdint.h>
#include <vector>
#include <queue>
#include <cstring>

std::vector<std::pair<int, int>> graph[100000];
bool visited[100000];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    --a; --b;

    // unidirectional paths
    for (int i = 0; i < m; ++i)
    {
        int nodeA, nodeB, dist;
        std::cin >> nodeA >> nodeB >> dist;
        --nodeA; --nodeB;
        graph[nodeB].push_back({nodeA, dist});
    }

    uint32_t dist[n];
    memset(dist, -1, sizeof(dist));
    dist[a] = dist[b] = 0;
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    q.push({0, a});
    if (a != b) q.push({0, b});

    while (!q.empty())
    {
        int current = q.top().second; q.pop();

        if (visited[current]) continue;
        visited[current] = true;

        for (auto neighbor : graph[current])
        {
            int newDist = dist[current] + neighbor.second;
            if (newDist < dist[neighbor.first])
            {
                dist[neighbor.first] = newDist;
                q.push({newDist, neighbor.first});
            }
        }
    }

    // distance
    uint64_t sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == UINT32_MAX) continue;
        sum += dist[i];
    }

    std::cout << sum << '\n';

    return 0;
}