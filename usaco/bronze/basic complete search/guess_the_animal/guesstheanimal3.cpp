// http://www.usaco.org/index.php?page=viewproblem2&cpid=893
// silly sol :P

#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <vector>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    int n, h; // number of animals, hints
    std::string str; // temp string input
    std::map<std::string, int> features;
    std::cin >> n;

    std::set<int> animals[n];

    for (int i = 0; i < n; ++i)
    {
        animals[i] = std::set<int>{};
        std::cin >> str >> h;
        for (int j = 0; j < h; ++j)
        {
            std::cin >> str;

            std::size_t val = features.size();
            auto iter = features.find(str);
            if (iter == features.end()) features[str] = val;
            else val = iter->second;

            animals[i].insert(val);
        }
    }

    std::size_t max = 0;
    for (int i = 0; i < n; ++i)
    {
        std::vector<int> intersect;
        for (int j = i + 1; j < n; ++j)
        {
            intersect.clear();
            std::set_intersection(animals[i].begin(), animals[i].end(), animals[j].begin(), animals[j].end(), std::inserter(intersect, intersect.begin()));
            max = std::max(max, intersect.size());
        }
    }

    std::cout << max + 1 << '\n';
    return 0;
}