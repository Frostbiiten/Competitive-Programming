// http://www.usaco.org/index.php?page=viewproblem2&cpid=712
// more bit manip :P

#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    int id, current = 0, count = 0, masks[26]; char c;
    std::memset(masks, 0, sizeof(masks));

    for (int i = 0; i < 52; ++i)
    {
        std::cin >> c;
        id = c - 'A';
        
        for (int j = 0, s = current; j < 26; ++j, s >>= 1) if (j != id && s & 1) masks[j] ^= 1 << id;

        current ^= 1 << id;
        if (((current >> id) & 1) == 0) count += __builtin_popcount(masks[id]);
    }

    std::cout << (count >> 1) << '\n';
    return 0;
}