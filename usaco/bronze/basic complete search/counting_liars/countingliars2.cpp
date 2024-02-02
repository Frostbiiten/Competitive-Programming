// http://www.usaco.org/index.php?page=viewproblem2&cpid=1228

#include <iostream>
#include <algorithm>

typedef std::pair<int, bool> hint;

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    int n; char dir;
    std::cin >> n;
    hint hints[n];

    int liars = 0;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> dir >> hints[i].first;
        hints[i].second = dir == 'G';
        liars += hints[i].second;
    }

    std::sort(hints, hints + n, [&](hint a, hint b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first; });
    bool o = true;
    int min = liars;

    for (int i = 0; i < n; ++i)
    {
        liars -= hints[i].second;
        liars += !o;
        min = std::min(min, liars);
        o = hints[i].second;
    }

    std::cout << min << '\n';

    return 0;
}