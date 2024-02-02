#include <iostream>
#include <vector>

int main()
{
    std::cin.tie(0); std::ios_base::sync_with_stdio(0);

    int n, pi = 0;
    std::cin >> n;

    char first, last, cur;
    std::cin >> first;
    last = first;
    for (int i = 1; i < n; ++i)
    {
        std::cin >> cur;
        if (last == cur) ++pi;
        last = cur;
    }

    if (first != last)
    {   
        std::cout << n;
        return 0;
    }
    if (n == 1)
    {
        std::cout << "1\n";
        return 0;
    }
    
    int v = n - 1 - pi;
    if (v == 0) v = 1;
    std::cout << v;

    return 0;
}