#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<std::vector<int>>> riceballs;
    riceballs.reserve(n);
    for (int i = 0; i < n; ++i) riceballs.push_back({{0}});
    for (int i = 0; i < n; ++i) std::cin >> riceballs[i][0][0];

    std::queue<std::pair<int, int>> q;

    // initial sweeps
    // size 2 & 3 windows
    for (int s = 1; s <= 2; ++s)
    {
        for (int i = 0; i < n - s; ++i)
        {
            if (riceballs[i][0] == riceballs[i + s][0])
            {
                q.push({i, s});
            }
        }
    }

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();
    }

    return 0;
}