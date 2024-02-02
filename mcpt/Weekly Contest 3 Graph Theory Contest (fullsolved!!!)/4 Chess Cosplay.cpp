#include <iostream>
#include <queue>

bool v[1000][1000];

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    std::pair<int, int> store, home;
    int n; char c;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> c;
            if (c == '.') continue;
            if (c == 'S') store = {i, j};
            else home = {i, j};
        }
    }


    // manhattan dist. for normal travel
    int normal = std::abs(store.first - home.first) + std::abs(store.second - home.second);

    // goofy bfs for knight
    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.push({store, 0});

    while (!q.empty())
    {
        auto current = q.front();
        q.pop();

        if (current.first == home)
        {
            std::cout << normal + current.second * 3 << '\n';
            return 0;
        }

        for (int o1 = -2; o1 <= 2; ++o1)
        {
            if (o1 == 0) ++o1;
            for (int o2 = -2; o2 <= 2; ++o2)
            {
                if (o2 == 0) ++o2;
                if (std::abs(o1) == std::abs(o2)) continue;

                std::pair<int, int> newPos = {current.first.first + o1, current.first.second + o2};
                if (newPos.first < 0 || newPos.second < 0 || newPos.first >= n || newPos.second >= n) continue;
                if (v[newPos.first][newPos.second]) continue;
                q.push({newPos, current.second + 1});
                v[newPos.first][newPos.second] = true;
            }
        }
    }

    // uh oh
    return 0;
}