#include <iostream>
#include <queue>
#include <stack>
#include <stdint.h>
#include <vector>
#include <cstring>
#include <set>

std::set<char> graph[26];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    uint32_t dist[26];
    int path[26];

    int n, q;
    std::cin >> n >> q;

    std::string s;
    std::cin >> s;

    // nodes
    int prev = s[0] - 'a';
    for (int i = 1; i < s.size(); ++i)
    {
        int current = s[i] - 'a';
        graph[prev].insert(current);
        prev = current;
    }

    for (int query = 0; query < q; ++query)
    {
        char a, b;
        std::cin >> a >> b;
        a -= 'a'; b -= 'a';

        memset(dist, -1, sizeof (dist));
        dist[a] = 0;

        memset(path, 0, sizeof (path));
        path[a] = -1;

        std::queue<int> q;
        q.push(a);

        bool found = false;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            if (current == b)
            {
                found = true;
                break;
            }
        
            int newDist = dist[current] + 1;
            for (auto neighbor : graph[current])
            {
                if (newDist < dist[neighbor])
                {
                    //path[neighbor] = current;
                    path[neighbor] = current;
                    dist[neighbor] = newDist;
                    q.push(neighbor);
                }
            }
        }

        if (found)
        {
            std::stack<char> l;

            int node = b;
            while (node != -1)
            {
                l.push(char(node + 'a'));
                node = path[node];
            }
            
            while (!l.empty())
            {
                std::cout << l.top();
                l.pop();
            }

            std::cout << '\n';
        }
        else
        {
            std::cout << "-1\n";
        }
    }

    return 0;
}