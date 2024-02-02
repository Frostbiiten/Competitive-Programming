#include <iostream>
#include <vector>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::cin >> n;

    std::vector<int> div;
    for (int i = 1; i <= 9; ++i)
    {
        if(n % i == 0) div.push_back(i);
    }

    for (int i = 0; i <= n; ++i)
    {
        bool val = false;
        for (int j = 0; j < div.size(); ++j)
        {
            if (i % (n / div[j]) == 0)
            {
                std::cout << div[j];
                val = true;
                break;
            }
        }
        if (!val) std::cout << '-';
    }

    return 0;
}