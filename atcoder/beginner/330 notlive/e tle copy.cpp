#include <iostream>
#include <set>
#include <map>

std::map<int, int> freq;

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;

    int a[n];

    int current;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> current;
        current = std::min(current, n);
        
        auto f = freq.find(current);
        if (f == freq.end()) freq[current] = 1;
        else ++(f->second);

        a[i] = current;
    }

    // find first minimum
    int ind, val;

    std::set<int> zeroInd;

    for (int i = 0; i <= n; ++i) if (!freq[i]) zeroInd.insert(i);

    for (int i = 0; i < q; ++i)
    {
        std::cin >> ind >> val;
        --ind;

        // decrement old, increment new & set
        auto oldInd = freq.find(a[ind]);
        if (oldInd->second == 1)
        {
            freq.erase(oldInd);
            zeroInd.insert(a[ind]);
        }
        else --(oldInd->second);

        auto newInd = freq.find(val);
        if (newInd == freq.end())
        {
            auto f = zeroInd.find(val);
            if (f != zeroInd.end()) zeroInd.erase(f);
            freq[val] = 1;
        }
        else ++(newInd->second);

        a[ind] = val;
        std::cout << *zeroInd.begin() << '\n';
    }

    return 0;
}