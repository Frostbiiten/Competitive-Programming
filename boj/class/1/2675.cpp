// https://www.acmicpc.net/problem/2675
#include <iostream>

int main()
{
    int n, r; std::string s;
    std::cin >> n;
    
    while (n--)
    {
        std::cin >> r >> s;
        for (int i = 0; i < s.size(); ++i)
        {
            for (int j = 0; j < r; ++j)
            {
                std::cout << s[i];
            }
        }

        std::cout << '\n';
    }
}