#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

std::vector<int> grid[1000001];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int m, n;
    std::cin >> m >> n;

    bool visited[m * n + 1];
    memset(visited, false, sizeof(visited));

    int ind = 0, val;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> val;
            grid[val].push_back(ind);
            ++ind;
        }
    }

    // positions in queue
    std::queue<int> q;
    q.push(m * n);

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        if (current == 1)
        {
            std::cout << "yes\n";
            return 0;
        }
    
        if (visited[current]) continue;
        visited[current] = true;
    
        for (auto pos : grid[current])
        {
            int a = pos / n;
            int b = pos - a * n;
            int target = (a + 1) * (b + 1);
            q.push(target);
        }
    }

    std::cout << "no\n";

    return 0;
}