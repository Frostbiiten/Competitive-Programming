#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int t, x, y, n;
    std::cin >> t;
    for (int test = 0; test < t; ++test)
    {
        std::cin >> x >> y >> n;
        int arr[n];
        arr[0] = x;
        arr[n - 1] = y;

        int diff = 1;
        for (int i = n - 2; i > 0; --i)
        {
            arr[i] = arr[i + 1] - diff;
            ++diff;
        }

        if (arr[1] - arr[0] >= diff)
        {
            for (int i = 0; i < n; ++i) std::cout << arr[i] << ' ';
            std::cout << '\n';
        }
        else
        {
            std::cout << "-1\n";
        }
    }

    return 0;
}