#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, m;
    std::cin >> n >> m;

    // parity check
    bool sumEven = !(m & 1);
    if (sumEven && (n & 1))
    {
        std::cout << "-1\n";
        return 0;
    }

    // print all but last
    int current = 1;
    int sum = 0;
    for (int i = 1; i < n; ++i)
    {
        std::cout << current << ' ';
        sum += current;
        current += 2;
    }

    int last = m - (sum % m);
    if (!(last & 1) && !(m & 1))
    {
        std::cout << "-1\n";
        return 0;
    }
    while (last < current || !(last & 1))
    {
        last += m;
    }
    std::cout << last << '\n';

    return 0;
}