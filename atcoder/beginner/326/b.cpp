#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::cin >> n;

    while (true)
    {
        int hundreds = n / 100;
        int tens = (n - hundreds * 100) / 10;
        int ones = n - hundreds * 100 - tens * 10;
        
        if (ones == tens * hundreds) break;
        ++n;
    }

    std::cout << n << '\n';
    return 0;
}
