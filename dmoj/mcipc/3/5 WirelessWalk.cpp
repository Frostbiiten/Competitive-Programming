#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0), std::cout.tie(0);
    
    int n, a, b;
    std::cin >> n >> a >> b;

    int delta = std::abs(a - b);

    std::multiset<int> distA;
    std::multiset<int> distB;
    int in;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        distA.insert(in);
    }

    for (int i = 0; i < n; ++i)
    {
        std::cin >> in;
        distB.insert(in);
    }

    int positions[n];
    int ind = 0;

    while (distA.size() > 0)
    {
        int maxA = *distA.rbegin();
        int maxB = *distB.rbegin();

        int pos;
        if (maxA > maxB)
        {
            if (a > b) pos = a - maxA;
            else pos = a + maxA;
            positions[ind++] = pos;
            distA.erase(distA.lower_bound(maxA));
            distB.erase(distB.lower_bound(std::abs(delta - maxA)));
        }
        else
        {
            if (b > a) pos = b - maxB;
            else pos = b + maxB;
            positions[ind++] = pos;
            distB.erase(distB.lower_bound(maxB));
            distA.erase(distA.lower_bound(std::abs(delta - maxB)));
        }
    }

    std::sort(positions, positions + n);
    for (int i = 0; i < n; ++i) std::cout << positions[i] << ' ';
    std::cout << '\n';

    return 0;
}