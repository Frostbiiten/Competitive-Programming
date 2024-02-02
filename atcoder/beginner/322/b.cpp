#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, m;
    std::string s, t;
    std::cin >> n >> m >> s >> t;

    int iBegin = t.find(s);
    int iEnd = t.find(s, t.size() - s.size());
    auto sBegin = iBegin == 0;
    auto sEnd = iEnd == t.size() - s.size();

    if (sBegin == sEnd)
    {
        if (!sBegin)
        {
            std::cout << '3';
        }
        else
        {
            std::cout << '0';
        }
    }
    else
    {
        if (sBegin)
        {
            std::cout << '1';
        }
        else
        {
            std::cout << '2';
        }
    }
    return 0;
}