#include <iostream>
#include <queue>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, m;
    std::cin >> n >> m;
    std::string map[m];

    for (int i = 0; i < m; ++i) std::cin >> map[i];

    std::queue<std::pair<int, int>> q;

    int max = -1;
    int components = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j] == '#')
            {
                int local = 0;
                ++components;

                q.push({i, j});
                map[i][j] = '.';
                while (!q.empty())
                {
                    auto current = q.front();
                    q.pop();
                    ++local;

                    for (int di = -1; di < 2; ++di)
                    {
                        for (int dj = -1; dj < 2; ++dj)
                        {
                            if (di == dj && di == 0) continue;

                            std::pair<int, int> newPos = {current.first + di, current.second + dj};
                            if (newPos.first < 0 || newPos.second < 0 || newPos.first >= m || newPos.second >= n) continue;
                            if (map[newPos.first][newPos.second] == '.') continue;
                            map[newPos.first][newPos.second] = '.';
                            q.push({newPos.first, newPos.second});
                        }
                    }
                }
                
                if (local > max) max = local;
            }
        }
    }

    std::cout << components << ' ' << max << '\n';

    return 0;
}