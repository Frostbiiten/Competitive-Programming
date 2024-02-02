#include <iostream>
#include <queue>
#include <cstring>
#include <stdint.h>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, m;
    std::pair<int, int> goal;
    std::string line;
    std::cin >> n >> m;

    uint32_t time[n][m];
    memset(time, -1, sizeof(time));

    std::string map[n];
    for (int i = 0; i < n; ++i) std::cin >> map[i];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            // expand
            if (map[i][j] == 'T')
            {
                for (int i2 = i - 1; i2 >= 0; --i2)
                {
                    if (map[i2][j] == '.') map[i2][j] = 'X';
                    else break;
                }

                for (int i2 = i + 1; i2 < n; ++i2)
                {
                    if (map[i2][j] == '.') map[i2][j] = 'X';
                    else break;
                }

                for (int j2 = j - 1; j2 >= 0; --j2)
                {
                    if (map[i][j2] == '.') map[i][j2] = 'X';
                    else break;
                }

                for (int j2 = j + 1; j2 < m; ++j2)
                {
                    if (map[i][j2] == '.') map[i][j2] = 'X';
                    else break;
                }
            }

            if (map[i][j] == 't')
            {
                map[i][j] = '.';
                goal = {i, j};
            }
        }
    }

    // possible?
    if (map[n - 1][0] == 'X' || map[n - 1][0] == 'W')
    {
        std::cout << "-1\n";
        return 0;
    }

    // standard bfs?
    std::queue<std::pair<int, int>> q;
    q.push({n - 1, 0});

    const std::pair<int, int> dirs[4] = {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0}
    };

    time[n - 1][0] = 0;
    while (!q.empty()) 
    {
        auto current = q.front();

        /*
        for (int i = 0; i < n; ++i)
        {
            std::string curr = map[i];
            if (current.first == i)
            {
                curr[current.second] = 'O';
            }
            std::cout << curr << '\n';
        }
        std::cout << '\n';
        */
        q.pop();

        if (current == goal)
        {
            std::cout << time[current.first][current.second] * 2 + 1;
            return 0;
        }

        int newTime = time[current.first][current.second] + 1;

        for (int i = 0; i < 4; ++i)
        {
            std::pair<int, int> newPos = {dirs[i].first + current.first, dirs[i].second + current.second};
            if (newPos.first < 0 || newPos.second < 0 || newPos.first >= n || newPos.second >= m) continue;
            if (map[newPos.first][newPos.second] != '.') continue;
            
            if (newTime < time[newPos.first][newPos.second])
            {
                time[newPos.first][newPos.second] = newTime;
                q.push(newPos);
            }
        }
    }

    std::cout << "-1\n";
    return 0;
}