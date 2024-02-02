#include <iostream>
#include <cstring>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int g[3][3], occ[9], count = 0;

    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            std::cin >> g[row][col];
        }
    }

    bool skip[3][3];
    for (int i = 0; i < 3; ++i) memset(skip[i], 0, sizeof(skip[i]));

    double total = 0;
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col)
        {
            if (skip[row][col]) continue;
            int cur = g[row][col];
            int chance = 0;

            // Row
            int sameRow = 0;
            for (int row2 = 0; row2 < 3; ++row2)
            {
                if (cur == g[row2][col])
                {
                    skip[row2][col] = true;
                    ++sameRow;
                }
            }
            chance += sameRow == 2;

            int sameCol = 0;
            for (int col2 = 0; col2 < 3; ++col2)
            {
                sameCol += cur == g[row][col2];
            }
            chance += sameCol == 2;

            int sameDiagA = 0;
            if (row == col)
            {
                for (int i = 0; i < 3; ++i)
                {
                    sameDiagA += cur == g[i][i];
                }
            }
            chance += sameDiagA == 2;

            int sameDiagB = 0;
            if (row == (2 - col))
            {
                for (int i = 0; i < 3; ++i)
                {
                    sameDiagB += cur == g[i][2 - i];
                }
            }
            chance += sameDiagB == 2;

            int choice = 0;
            if (chance)
            {
                choice += 3;
            }
            if (chance > 0)
            choice += (chance - 1) * 2;
        
            if (chance && choice)
            {
                total += (double)chance / choice;
            }
        }
    }

    return 0;
}