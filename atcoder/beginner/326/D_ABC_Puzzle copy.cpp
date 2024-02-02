#include <iostream>
#include <queue>

int main()
{
    int n;
    std::string r, c;
    std::cin >> n >> r >> c;

    //int rowsPossible = ~0;
    //int colsPossible = ~0;
    int config = ~0;
    int maxSet = __builtin_popcount(config);

    for (int row = 0; row < n; ++row)
    {
        int charNum = 1 << (r[row] - 'A');
        int mask = charNum << (3 * row);
        config = config & (~mask);
    }

    for (int col = 0; col < n; ++col)
    {
        int charNum = 1 << (r[col] - 'A');
        int mask = charNum << ((3 * col) + 15);
        config = config & (~mask);
    }

    std::queue<int> q;
    q.push(config);

    while(!q.empty())
    {
        if (maxSet - __builtin_popcount(config) == n * n * 2)
        {
            std::cout << "found!\n";
            break;
        }

        
    }

    for (int x = 0; x < n; ++x)
    {
        for (int y = 0; y < n; ++y)
        {

        }
    }

    return 0;
}