#include <iostream>
#include <vector>
#include <queue>

// upstream, percent
std::vector<std::pair<int, int>> graph[100000];
int pollution[100000];
int p[100000];

std::pair<int, double> influence[100000];

int main()
{
    int n, m;
    std::cin >> n >> m;
    
    // start from point that has nothing pointing to it?
    int u, v, f;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> u >> v >> f;

        --u; --v;
        graph[v].push_back({u, f});
    }

    for (int i = 0; i < n; ++i) std::cin >> p[i];


    // dp dfs (its joever)

    // node, influence percent
    ;

    auto dfs = [&](int node)
    {
        // set pollution to p[i]
        pollution[node] = p[node];


        //for ()
        //influence[]
        
    };

    dfs(0);

    /*
    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        pollution[current] = p[current];

        for (auto upstream : graph[current])
        {

        }
    }
    */

    return 0;
}