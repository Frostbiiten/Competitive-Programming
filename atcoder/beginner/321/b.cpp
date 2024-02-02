#include <iostream>

int main()
{
    int n, x, a;
    std::cin >> n >> x;

    int sum = 0, min = 101, max = -1;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> a;
        sum += a;
        min = std::min(min, a);
        max = std::max(max, a);
    }
    sum = sum - min - max;

    int diff = x - sum;
    std::cout << diff << '\n';

    return 0;
}