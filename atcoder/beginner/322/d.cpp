#include <iostream>
#include <cstring>
#include <cstdint>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    char c;
    std::set<int> grids[3];


    bool orig[4][4];
    int total = 0;
    for (int grid = 0; grid < 3; ++grid)
    {
        memset(orig, 0, sizeof(orig));
        for (int y = 0; y < 4; ++y)
        {
            for (int x = 0; x < 4; ++x)
            {
                std::cin >> c;
                orig[y][x] = c == '#';
                total += orig[y][x];
            }
        }

        // generate base rotations
        for (int rot = 0; rot < 4; ++rot)
        {
            int id = 0;
            int left = 4, right = 4, top = 4, bottom = 4;
            for (int y = 0; y < 4; ++y)
            {
                for (int x = 0; x < 4; ++x)
                {
                    int p = orig[y][x];
                    if (p)
                    {
                        id |= p << (y * 4 + x);
                        left = std::min(left, x);
                        right = std::min(right, 3 - x);
                        top = std::min(top, y);
                        bottom = std::min(bottom, 3 - y);
                    }
                }
            }

            // translate the id from top left
            id >>= (top * 4);
            id >>= left;

            // horizontal
            for (int x = 0; x <= left + right; ++x)
            {
                // vertical
                for (int y = 0; y <= top + bottom; ++y)
                {
                    // add new ID
                    int newID = (id << x) << (y * 4);
                    grids[grid].insert(newID);
                }
            }

            if (rot == 3) break;

            // rotate for next
            for (int i = 0; i < 4; i++)
            {
                for (int j = i; j < 4; j++)
                {
                    std::swap(orig[i][j], orig[j][i]);
                }
            }

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    std::swap(orig[i][j], orig[i][3 - j]);
                }
            }
        }
    }

    if (total == 16)
    {
        for (auto a : grids[0])
        {
            for (auto b : grids[1])
            {
                for (auto c : grids[2])
                {
                    int ab = a & b;
                    int bc = b & c;
                    int ca = a & c;
                    if (ab == 0 && bc == 0 && ca == 0)
                    {
                        std::cout << "Yes\n";
                        return 0;
                    }
                }
            }
        }
    }

    std::cout << "No\n";
    return 0;
}
