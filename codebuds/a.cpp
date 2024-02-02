#include <iostream>
#include <cstring>
#include <climits>
#include <queue>

typedef std::pair<int, int> coordinate;

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, m; char in;
    std::cin >> n >> m;

    coordinate jasper, jasmine, flower;

    bool grid[n][m];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> in;
            if (in == 'A')
            {
                jasper = {i, j};
                grid[i][j] = true;
            }
            else if (in == 'B')
            {
                jasmine = {i, j};
                grid[i][j] = true;
            }
            else if (in == 'F')
            {
                flower = {i, j};
                grid[i][j] = true;
            }
            else
            {
                grid[i][j] = in == 'O';
            }
        }
    }

    int dist[n][m];
    for (int i = 0; i < n; ++i) std::fill_n(dist[i], m, INT_MAX);

    std::queue<coordinate> q;
    dist[flower.first][flower.second] = 0;
    q.push(flower);

    while(!q.empty())
    {
        coordinate current = q.front();
        int curDist = dist[current.first][current.second];
        q.pop();

        coordinate neighbors[4] =
        {
            {current.first + 1, current.second},
            {current.first - 1, current.second},
            {current.first, current.second + 1},
            {current.first, current.second - 1}
        };

        for (int i = 0; i < 4; ++i)
        {
            auto neighbor = neighbors[i];
            if (neighbor.first >= 0 && neighbor.first < n &&
                neighbor.second >= 0 && neighbor.second < m &&
                grid[neighbor.first][neighbor.second])
            {
                int newVal = curDist + 1;
                if (newVal < dist[neighbor.first][neighbor.second])
                {
                    dist[neighbor.first][neighbor.second] = newVal;
                    q.push(neighbor);
                }
            }
        }
    }

    int a = dist[jasmine.first][jasmine.second];
    int b = dist[jasper.first][jasper.second];
    if (a == INT_MAX || b == INT_MAX) std::cout << "-1\n";
    else std::cout << a + b << '\n';

    return 0;
}