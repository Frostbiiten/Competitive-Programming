#include <iostream>

int main()
{
    int n;
    std::string r, c;
    std::cin >> n >> r >> c;

    // int grid[n][n];
    __int128 grid = ~0;

    for (int row = 0; row < n; ++row)
    {
        __int128 charNum = 1 << (r[row] - 'A');
        __int128 mask = charNum << (3 * n * row);
        grid = grid & (~mask);
    }

    for (int col = 0; col < n; ++col)
    {
        __int128 charNum = 1 << (c[col] - 'A');
        __int128 mask = charNum << (3 * col);
        grid = grid & (~mask);
    }

    return 0;
}