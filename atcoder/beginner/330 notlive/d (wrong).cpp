#include <iostream>

std::string str[2000];

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::cin >> n;

    // scan each row
    for (int i = 0; i < n; ++i) std::cin >> str[i];

    // total number of L's
    int count = 0;

    // iterate through 2x2 block
    for (int y = 0; y < n - 1; ++y)
    {
        for (int x = 0; x < str[y].size() - 1; ++x)
        {
            int oCount = 
                (str[y][x] == 'o')
            +   (str[y + 1][x] == 'o')
            +   (str[y][x + 1] == 'o')
            +   (str[y + 1][x + 1] == 'o');

            if (oCount == 3) ++count;
            else if (oCount == 4) count += 4;
        }
    }

    std::cout << count << '\n';

    return 0;
}