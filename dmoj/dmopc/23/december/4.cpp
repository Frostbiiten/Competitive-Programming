#include <functional>
#include <iostream>
#include <stdint.h>
#include <vector>
#include <cstring>
#include <cstdint>

std::vector<std::pair<int, int>> g[1000001];
uint32_t dist[1000001];

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    std::function<void(int)> f;
    uint64_t sum = 0;
    f = [&](int current)
    {
        uint32_t c = dist[current];
        dist[c] = 1;

        for (auto p : g[current])
        {
            if (dist[p.first] != 0) break;
            dist[p.first] = 1;
            sum += dist[p.first];
            f(p.first);
        }
    };

    dist[1] = 1;
    f(1);

    // ??
    std::cout << sum;
}