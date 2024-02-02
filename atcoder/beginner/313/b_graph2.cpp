#include <iostream>
#include <cstring>
#include <queue>
#include <set>

// is the graph always a tree?

int main()
{
    int n, m, weak, strong;
    std::cin >> n >> m;

    std::uint64_t graph[n];
    memset(graph, false, sizeof(graph));

    for (int i = 0; i < m; ++i)
    {
        std::cin >> strong >> weak;
        --strong; --weak;
        graph[strong] |= 1ull << weak;
    }

    std::uint64_t strongestMask = UINT64_MAX >> (64 - n);

    int id = -1;
    for (int i = 0; i < n; ++i)
    {
        std::queue<int> q;
        std::uint64_t s = 0;
        q.push(i);

        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            
            std::uint64_t connections = graph[c];
            for (int connection = 0; connections > 0; ++connection, connections >>= 1)
            {
                if (connections & 1 && !((s >> connection) & 1))
                {
                    q.push(connection);
                }
            }

            s |= 1ull << c;
        }

        if (s == strongestMask)
        {
            if (id == -1)
            {
                id = i + 1;
            }
            else
            {
                id = -1;
                break;
            }
        }
    }

    std::cout << id << '\n';
}