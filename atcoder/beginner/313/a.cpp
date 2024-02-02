#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, s1, s;
    std::cin >> n;
    int skill[n];

    int max = -1, maxIndex;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> s;
        if (i == 0) s1 = s;
        if (s >= max)
        {
            max = s;
            maxIndex = i;
        }
    }

    if (maxIndex == 0) std::cout << "0\n";
    else std::cout << max - s1 + 1 << '\n';

    return 0;
}