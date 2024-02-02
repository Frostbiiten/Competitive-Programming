#include <iostream>

int main()
{
    int n, total = 0;
    std::cin >> n;

    bool rowsA[n][n];

    char c;
    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            std::cin >> c;
            rowsA[row][col] = (c == '1');
        }
    }

    for (int row = 0; row < n; ++row)
    {
        for (int col = 0; col < n; ++col)
        {
            std::cin >> c;
            if (rowsA[row][col] != (c == '1'))
            {
                std::cout << "at " << row << ", " << col << '\n';
                ++total;
            }
        }
    }
    
    std::cout << total << '\n';

    return 0;
}