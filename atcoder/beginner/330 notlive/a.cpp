#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, l, c;
    std::cin >> n >> l;

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> c;
        count += (c >= l);
    }

    std::cout << count << '\n';
}