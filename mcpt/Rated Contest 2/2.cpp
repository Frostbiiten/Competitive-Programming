#include <iostream>
#include <queue>

// 0 = unvisited
// > 0 = friends
// < 0 = visited
int visited[1000][1000];
int elevation[1000][1000];

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m, h;
    std::cin >> n >> m >> h;

    // friend positions
    int i, j;
    for (int currentFriend = 0; currentFriend < n; ++currentFriend)
    {
        std::cin >> i >> j;
        --i; --j;

        ++visited[i][j];
    }

    int elev;
    for (int row = 0; row < m; ++row)
    {
        for (int col = 0; col < m; ++col)
        {
            std::cin >> elev;
            elevation[row][col] = elev;
        }
    }
    
    // bottom right
    int total = visited[m - 1][m - 1];
    visited[m - 1][m - 1] = -1;

    // start bfs from bottm right;
    std::queue<std::pair<int, int>> q;
    q.push({m - 1, m - 1});

    while (!q.empty())
    {
        auto current = q.front();
        int currentHeight = elevation[current.first][current.second];
        q.pop();

        for (int yO = -1; yO < 2; ++yO)
        {
            for (int xO = -1; xO < 2; ++xO)
            {
                if (std::abs(yO) == std::abs(xO)) continue;
                std::pair<int, int> newP = {current.first + xO, current.second + yO};
                
                // bound check
                if (newP.first < 0 || newP.second < 0 || newP.first >= m || newP.second >= m) continue;

                // check if visited
                int visitState = visited[newP.first][newP.second];
                if (visitState < 0) continue;

                if (std::abs(currentHeight - elevation[newP.first][newP.second]) <= h)
                {
                    q.push(newP);

                    // add friends present, set to visited
                    total += visitState;
                    visited[newP.first][newP.second] = -1;
                }
            }
        }
    }

    std::cout << total << '\n';
    return 0;
}