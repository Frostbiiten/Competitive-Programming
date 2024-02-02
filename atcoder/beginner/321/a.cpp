#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n; std::string str;
    std::cin >> n;
    str = std::to_string(n);

    for (int i = 1; i < str.size(); ++i)
    {
        if (str[i] < str[i - 1])
        {
            std::cout << "No\n";
            return 0;
        }
    }

    std::cout << "Yes\n";
    return 0;
}