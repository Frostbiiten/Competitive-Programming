#include <iostream>
#include <cctype>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0), std::cout.tie(0);

    int n; char c;
    std::cin >> n;
    std::cin >> std::noskipws >> c;

    int total = 0, es = 0, co = 0;
    while (std::cin >> std::noskipws >> c)
    {
        c = std::tolower(c);
        bool e = c == 'e';
        if (c == 'a' || e || c == 'i' || c == 'o' || c == 'u')
        {
            ++total;
            es += e;
        }
        ++co;
        if (co == n) break;
    }

    if (es << 1 > total) std::cout << "see me after class...\n";
    else std::cout << "great work!\n";

    return 0;
}