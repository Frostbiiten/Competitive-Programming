#include <iostream>
#include <cstring>

int main()
{
    int h, w; char in;
    std::cin >> h >> w;
    
    int grid[h][w];
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            std::cin >> in;
            grid[i][j] = in - 'a';
        }
    }

    bool markedRows[h], markedCols[w];
    memset(markedRows, 0, h);
    memset(markedCols, 0, w);

    while (true)
    {
        bool m = false;

        for (int i = 0; i < h; ++i)
        {
            if (markedRows[i]) continue;
            int v = grid[i][0];
            for (int j = 0; j < w; ++j)
            {
                if (markedCols[j] && grid[i][j] != v)
                {
                    markedRows[i] = true;
                    m = true;
                    break;
                }
            }
        }

        for (int j = 0; j < w; ++j)
        {
            if (markedCols[j]) continue;
            int v = grid[0][j];
            for (int i = 0; i < h; ++i)
            {
                if (markedRows[i] && grid[i][j] != v)
                {
                    markedCols[j] = true;
                    m = true;
                    break;
                }
            }
        }

        if (!m) break;
    }

    int c = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            c += markedRows[i] && markedCols[j];
        }
    }
    std::cout << c << '\n';

    return 0;
}