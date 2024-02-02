#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

typedef std::pair<int, int> edge;

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    --a; --b;
    
    int u, v, w;

    std::vector<edge> graph[n];

    for (int i = 0; i < m; ++i)
    {
        std::cin >> u >> v >> w;
        --u; --v;
        graph[u].push_back({v, w});
    }

    std::pair<int, int> dist[n];
    std::fill_n(dist, n, std::make_pair(INT_MAX, INT_MAX));
    dist[a] = {0, INT_MAX};

    std::priority_queue<edge, std::vector<edge>, std::greater<edge>> q;
    q.push({0, a});

    while(!q.empty())
    {
        auto t = q.top();
        int node = t.second;
        int cost = t.first;
        q.pop();

        if (dist[node].second < cost) continue;

        for (auto neighbor : graph[node])
        {
            int newCost = cost + neighbor.second;
            if (newCost < dist[neighbor.first].first)
            {
                dist[neighbor.first].second = dist[neighbor.first].first;
                dist[neighbor.first].first = newCost;
                q.push({newCost, neighbor.first});
            }
            else if (newCost > dist[neighbor.first].first && newCost < dist[neighbor.first].second)
            {
                dist[neighbor.first].second = newCost;
                q.push({newCost, neighbor.first});
            }
        }
    }

    int d = dist[b].second;
    if (d == INT_MAX) d = -1;
    std::cout << d << '\n';
    return 0;
}