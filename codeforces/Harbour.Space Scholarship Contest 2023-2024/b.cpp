#include <iostream>
#include <algorithm>

int main()
{
    //std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int t, n, k; char in;
    std::string str;
    std::cin >> t;
    for (int test = 0; test < t; ++test)
    {
        std::cin >> n >> k;

        if ((k & 1) == 0)
        {
            // even
            std::cin >> str;
        }
        else
        {
            // odd k, indexes stuck with even/odd, just use i + 2 swaps
            char arr[2][n];
            bool curArr = false;
            for (int i = 0; i < n; ++i)
            {
                std::cin >> arr[curArr][i >> 1];
                curArr = !curArr;
            }

            std::size_t evenLen = (n + 1) >> 1;
            std::size_t oddLen = n >> 1;

            std::sort(arr[0], arr[0] + evenLen);
            std::sort(arr[1], arr[1] + oddLen);

            curArr = false;
            for (int i = 0; i < n; ++i)
            {
                std::cout << arr[curArr][i >> 1];
                curArr = !curArr;
            }
            std::cout << '\n';
        }
    }

    return 0;
}