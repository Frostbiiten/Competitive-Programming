#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int t, n, arr[9];
    std::cin >> t;

    while (t--)
    {
        std::cin >> n;

        int prod = 1, z = 0;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> arr[i];
            if (arr[i]) prod *= arr[i];
            else ++z;
        }

        if (z > 1)
        {
            std::cout << "0\n";
            continue;
        }
        else if (z == 1)
        {
            std::cout << prod << '\n';
            continue;
        }

        int max = -1;
        for (int i = 0 ; i < n; ++i)
        {
            if (arr[i])
            {
                max = std::max(max, (prod / arr[i]) * (arr[i] + 1));
            }
        }
        std::cout << max << '\n';
    }
}