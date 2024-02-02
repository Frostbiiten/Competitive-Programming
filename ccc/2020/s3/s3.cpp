#include <iostream>
#include <cstring>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    std::string n, h;
    std::cin >> n >> h;
    std::int64_t hashArr[h.size()], pow[h.size()], prime = 25165843;
    hashArr[0] = 0;
    pow[0] = 1;

    // generate combined frequency array
    int m[26]; memset(m, 0, sizeof(m));
    for (std::size_t i = 0; i < n.size(); ++i)
    {
        // add for haystack, subtract for needle (zeroed array means equal freq)
        --m[n[i] - 'a'];
        ++m[h[i] - 'a'];
    }

    // hash PSA
    for (int i = 0; i < h.size(); ++i)
    {
        hashArr[i] = (h[i] - 'a' + 1) % prime;
        if (i) pow[i] = (pow[i - 1] * 31) % prime;
    }

    // number of differing digits between window and needle
    int diff = 0;
    for (int i = 0; i < 26; ++i) diff += std::abs(m[i]);

    std::set<int> sv; // set of hashed found permutations
    for (std::size_t offset = n.size(); offset <= h.size(); ++offset)
    {
        if (!diff)
        {
            std::int64_t hash = (hashArr[offset] + prime - hashArr[offset - n.size()]) % prime;
            sv.insert(hash); // same needle and window frequency
        }

        if (offset == h.size()) break;

        // handle frequency array
        int add = h[offset] - 'a';
        if (m[add] < 0) --diff;
        else ++diff;
        ++m[add];

        int sub = h[offset - n.size()] - 'a';
        if (m[sub] > 0) --diff;
        else ++diff;
        --m[sub];
    }

    std::cout << sv.size() << '\n';

    return 0;
}
