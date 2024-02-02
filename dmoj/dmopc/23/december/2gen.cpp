#include <functional>
#include <iostream>

int grid[2000][2000];

const std::pair<int, int> offset[8] = {
    {2, 1},
    {1, 2},
    {-2, 1},
    {-1, 2},
    {2, -1},
    {1, -2},
    {-2, -1},
    {-1, -2},
};

int main()
{
    std::function<bool(std::pair<int, int>, int, int, int&)> dfs;
    dfs = [&](std::pair<int, int> point, int val, int size, int& remaining) -> bool
    {

        int og = grid[point.first][point.second];
        bool dec = !grid[point.first][point.second];

        // decrease if nothing already there
        if (dec) --remaining;

        grid[point.first][point.second] = val;

        if (!remaining)
        {
            std::cout << "done!\n";
            return true;
        }

        for (int i = 0; i < 8; ++i)
        {
            std::pair<int, int> newP = {point.first + point.first, point.second + point.second};
            if (newP.first < 0 || newP.second < 0 || newP.first >= size || newP.second >= size) continue;

            if (grid[newP.first][newP.second]) continue;

            dfs(newP, 1, size, remaining);
            dfs(newP, 2, size, remaining);
        }

        grid[point.first][point.second] = og;
        if (dec) ++remaining;
        return false;
    };

    for (int size = 4; size < 8; ++size)
    {
        int remaining = size * size;
        dfs({0, 0}, 1, size, remaining);
    }
}