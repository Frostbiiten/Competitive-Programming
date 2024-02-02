#include <iostream>

int main()
{
    const std::string id = "vika";
    int t, w, h;
    std::cin >> t;

    std::string grid[h];

    for (int c = 0; c < t; ++c)
    {
        std::cin >> h >> w;

        int ind = 0;
        for (int y = 0; y < h; ++y) std::cin >> grid[y];

        if (w >= 4)
        {
            for (int x = 0; x < w; ++x)
            {
                if (ind == 4) break;
                for (int y = 0; y < h; ++y)
                {
                    if (grid[y][x] == id[ind])
                    {
                        ++ind;
                        if (ind == 4)
                        {
                            std::cout << "YES\n";
                        }
                        break;
                    }
                }
            }
        
            if (ind == 4) continue;
        }

        std::cout << "NO\n";
     }
}