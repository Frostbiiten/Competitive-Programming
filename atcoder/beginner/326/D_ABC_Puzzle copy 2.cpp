#include <functional>
#include <iostream>
#include <queue>
#include <set>

int main()
{
    int n;
    std::string r, c;
    std::cin >> n >> r >> c;

    char grid[n * n];
    std::fill_n(grid, n * n, '.');

    int rowCount[n][3];
    int colCount[n][3];
    for (int i = 0; i < n; ++i)
    {
        rowCount[i][0] = rowCount[i][1] = rowCount[i][2] = 0;
        colCount[i][0] = colCount[i][1] = colCount[i][2] = 0;
    }

    std::function<bool(int)> perm;
    perm = [&](int ind) -> bool
    {
        // check if valid
        if (ind == n * n - 1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (rowCount[i][0] == rowCount[i][1] == rowCount[i][2] ==
                    colCount[i][0] == colCount[i][1] == colCount[i][2] == 1)
                {
                    for (int y = 0; y < n; ++y)
                    {
                        for (int x = 0; x < n; ++x)
                        {
                            std::cout << grid[y * n + x];
                        }
                        std::cout << '\n';
                    }

                    return true;
                }
            }

            return false;
        }

        int nums = 7;
        int row = ind / n;
        int col = n - (row * n);
        nums = nums & (7 & ~r[row]);
        nums = nums & (7 & ~c[col]);

        for (int current = 0; current < 4; ++current)
        {
            if (current == 4)
            {
                grid[col + row * n] = ' ';
                if (perm(ind + 1)) return true;
            }
            else
            {
                if (!(nums & (1 << current))) continue;
                
                ++rowCount[row][current];
                ++colCount[col][current];

                grid[col + row * n] = 'A' + current;
                if (perm(ind + 1)) return true;

                --rowCount[row][current];
                --colCount[col][current];
            }
        }

        return false;
    };

    perm(0);

    return 0;
}