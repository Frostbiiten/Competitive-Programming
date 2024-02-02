#include <iostream>
#include <cstring>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int rows[9];
    int cols[9];
    int groups[9];
    memset(rows, 0, sizeof(rows));
    memset(cols, 0, sizeof(cols));
    memset(groups, 0, sizeof(groups));

    int current;
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            std::cin >> current;

            if ((rows[row] >> current) & 1)
            {
                std::cout << "No\n";
                return 0;
            }
            rows[row] |= 1 << current;

            if ((cols[col] >> current) & 1)
            {
                std::cout << "No\n";
                return 0;
            }
            cols[col] |= 1 << current;

            int curGroup = (row / 3) * 3 + col / 3;
            if ((groups[curGroup] >> current) & 1)
            {
                std::cout << "No\n";
                return 0;
            }
            groups[curGroup] |= 1 << current;
        }
    }

    std::cout << "Yes\n";
}