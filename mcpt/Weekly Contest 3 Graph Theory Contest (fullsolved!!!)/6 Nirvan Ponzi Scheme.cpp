#include <complex.h>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include <cstdint>
#include <cstring>

std::pair<std::vector<int>, int64_t> graph[5000];

struct p
{
    public:
    int node;
    int64_t money;
    std::vector<int> last;

    p(int node, int64_t money) : node(node), money(money)
    {
        last.reserve(5000);
    }
};

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, k, m;
    std::cin >> n >> k >> m;

    // investments (there is an investor in each city)
    for (int i = 0; i < n; ++i) std::cin >> graph[i].second;

    // connections
    int a, b;
    for (int i = 0; i < m; ++i)
    {
        std::cin >> a >> b; --a; --b;
        graph[a].first.push_back(b);
    }

    // queue with initial position
    std::queue<p> q;
    q.push(p{0, graph[0].second});

    int64_t max = 0;

    while (!q.empty())
    {
        // front
        p current = q.front();
        q.pop();

        // explore neighbors
        for (auto next : graph[current.node].first)
        {
            // get next point
            auto nextP = p{next, current.money + graph[next].second};
            nextP.last = current.last;

            // remember last k nodes
            nextP.last.push_back(current.node);

            // check for payback
            if (nextP.last.size() >= k)
            {
                int64_t loss = graph[nextP.last[nextP.last.size() - k]].second;

                for (int64_t l = 2; l <= loss; ++l)
                {
                    if (loss % l == 0)
                    {
                        loss += l;
                        break;
                    }
                }

                nextP.money -= loss;
            }
            
            if (nextP.money > max) max = nextP.money;
            q.push(nextP);
        }
    }

    std::cout << max << '\n';
    return 0;
}