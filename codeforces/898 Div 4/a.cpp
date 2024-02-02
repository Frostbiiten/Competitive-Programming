#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int t; std::string in;
    std::cin >> t;

    while (t--)
    {
        std::cin >> in;

        int err = 0;
        for (int i = 0; i < 3; ++i) err += in[i] != ('a' + i);
        
        if (err < 3) std::cout << "YES\n";
        else std::cout << "NO\n";
    }
}