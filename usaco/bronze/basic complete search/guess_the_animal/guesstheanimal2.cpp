// http://www.usaco.org/index.php?page=viewproblem2&cpid=893
// silly sol :P

#include <iostream>
#include <bitset>
#include <cstring>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n, h; // number of animals, hints
    std::string str; // temp string input
    std::map<std::string, int> features;
    std::cin >> n;

    std::bitset<100> animals[n];

    for (int i = 0; i < n; ++i)
    {
        animals[i] = std::bitset<100>{};
        std::cin >> str >> h;
        for (int j = 0; j < h; ++j)
        {
            std::cin >> str;

            std::size_t val = features.size();
            auto iter = features.find(str);
            if (iter == features.end()) features[str] = val;
            else val = iter->second;

            animals[i].set(val, true);
        }
    }

    std::size_t max = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            max = std::max(max, (animals[i] & animals[j]).count());
        }
    }

    std::cout << max + 1 << '\n';
    return 0;
}