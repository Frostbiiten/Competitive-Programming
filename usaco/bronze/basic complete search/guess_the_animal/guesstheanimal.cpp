// http://www.usaco.org/index.php?page=viewproblem2&cpid=893
// silly sol :P

#include <iostream>
#include <cstring>
#include <map>

int main()
{
    //std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int n, h; // number of animals, hints
    std::string str; // temp string input
    std::map<std::string, int> features;
    std::cin >> n;

    __uint128_t animals[n];
    std::memset(animals, 0, sizeof(animals));

    for (int i = 0; i < n; ++i)
    {
        std::cin >> str >> h;
        for (int j = 0; j < h; ++j)
        {
            std::cin >> str;

            int val = features.size();
            if (features.count(str))  val = features[str];
            else features[str] = val;

            animals[i] |= (__uint128_t)1 << val;
        }
    }

    int max = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            auto m = animals[i] & animals[j];
            max = std::max(max, __builtin_popcountll(m) +  __builtin_popcountll(m >> 64));
        }
    }

    std::cout << max + 1;
    return 0;
}