#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>

std::pair<int, std::vector<int>> ways[50][50];

int main()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::string line;
    bool grid[n][m];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> line;
        for (int j = 0; j < m; ++j) grid[i][j] = line[j] == '1';
    }

    ways[0][0] = {1, {}};

    for (int i = 1; i < n; ++i)
    {
        if (!grid[i][0]) break;
        ways[i][0] = {1, {}};
    }

    for (int j = 1; j < m; ++j)
    {
        if (!grid[0][j]) break;
        ways[0][j] = {1, {}};
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ways[i][j].second.resize(2500);
            if (!grid[i][j]) ways[i][j].second[i + j * n] = 1;
        }
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            ways[i][j].first = ways[i - 1][j].first + ways[i][j - 1].first;
            for (int z = 0; z < 2500; ++z)
            {
                ways[i][j].second[z] = ways[i - 1][j].second[z] + ways[i][j - 1].second[z];
            }
        }
    }

    // first = index, second = count
    std::pair<int, int> sorted[2500];
    for (int i = 0; i < 2500; ++i)
    {
        sorted[i] = {i, ways[n - 1][m - 1].second[i]};
        if (sorted[i].second != 0) std::cout << sorted[i].first << ", " << sorted[i].second << '\n';
    }
    std::sort(sorted, sorted + 2500, [](std::pair<int, int> a, std::pair<int, int> b){ return a.second > b.second; });

    std::cout << "helko"; //ways[n - 1][m - 1];
}