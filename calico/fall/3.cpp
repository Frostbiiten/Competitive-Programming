#include <iostream>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int t;
    std::cin >> t;

    while (t--)
    {
        int n, m;
        std::cin >> n >> m;

        int start[n];

        for (int i = 0; i < n; ++i) std::cin >> start[i];

        int end, max = 0;
        for (int i = 0; i < n; ++i)
        {
            std::cin >> end;
            if (start[i] > end) end += m;
            max = std::max(max, end - start[i]);
        }

        std::cout << max << '\n';
    }
}