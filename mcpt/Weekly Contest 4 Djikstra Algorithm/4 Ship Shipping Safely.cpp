#include <iostream>
#include <cstring>
#include <queue>
#include <stdint.h>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n;
    std::cin >> n;

    int danger[n * n];

    bool visited[n * n];
    memset(visited, 0, sizeof(visited));

    uint32_t cost[n * n];
    memset(cost, -1, sizeof(cost));

    // grid
    int ind = 0;
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            std::cin >> danger[ind];
            ++ind;
        }
    }

    auto conv = [n](int x, int y) -> int { return y * n + x; };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

    cost[0] = danger[0];
    q.push({danger[0], 0});

    while (!q.empty())
    {
        int current = q.top().second;
        q.pop();

        if (visited[current]) continue;
        visited[current] = true;

        int realY = current / n;
        int realX = current - realY * n;

        // offsets
        for (int y0 = -1; y0 <= 1; ++y0)
        {
            for (int x0 = -1; x0 <= 1; ++x0)
            {
                if (x0 == 0 && y0 == 0) continue;

                int newX = realX + x0;
                int newY = realY + y0;

                if (newX < 0 || newY < 0 || newX >= n || newY >= n) continue;

                int convPos = conv(newX, newY);
                int newCost = cost[current] + danger[convPos];

                if (newCost < cost[convPos])
                {
                    cost[convPos] = newCost;
                    q.push({newCost, convPos});
                }
            }
        }
    }

    std::cout << cost[n * n - 1] << '\n';
    return 0;
}