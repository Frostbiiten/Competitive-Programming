#include <iostream>
#include <queue>
#include <vector>
#include <climits>

struct town
{
    std::vector<int> adj;
    int paparazzo, p_move, dist, next;

    town() : p_move{1}, paparazzo{0}, dist{INT_MAX}, adj{} {}
};

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
    int n, m, u, v;
    std::cin >> n >> m;

    town towns[n];
    for (int i = 0; i < n - 1; ++i)
    {
        std::cin >> u >> v;
        --u; --v;
        towns[u].adj.push_back(v);
        towns[v].adj.push_back(u);
    }

    int a[m];
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a[i];
        --a[i];
    }
    
    for (int time = 0; time < m; ++time)
    {
        int pos = a[time];

        for (int i = 0; i < n; ++i)
        {
            towns[i].next = i;
            towns[i].dist = INT_MAX;
            std::swap(towns[i].p_move, towns[i].paparazzo);
        }

        // bfs
        std::queue<int> q;
        towns[pos].dist = 0;
        q.push(pos);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            for (auto adj: towns[cur].adj)
            {
                int newDist = towns[cur].dist + 1;
                if (towns[adj].dist > newDist)
                {
                    towns[adj].dist = newDist;
                    towns[adj].next = cur;
                    q.push(adj);
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            towns[towns[i].next].p_move += towns[i].paparazzo;
            towns[i].paparazzo = 0;
        }

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            count += towns[i].p_move != 0;
        }

        std::cout << count << '\n';
    }
}