#include <ios>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, a, b;
    std::cin >> n;
    
    std::cin >> a;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> b;
        if (a != b)
        {
            std::cout << "No\n";
            return 0;
        }
        a = b;
    }

    std::cout << "Yes\n";
}