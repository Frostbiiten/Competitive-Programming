#include <iostream>
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
        
        auto f = freq.find(current);
        if (f == freq.end()) freq[current] = 1;
        else ++(f->second);

        a[i] = current;
    }

    // find first minimum
    int ind, val, min = 0;

    // otherwise, min is 0 (bc not found)
    if (freq.find(0) != freq.end()) 
    {
        for (auto used : freq)
        {
            min = used.first + 1;
            if (freq.find(min) == freq.end()) break;
        }
    }

    for (int i = 0; i < q; ++i)
    {
        std::cin >> ind >> val;
        --ind;

        // decrement old, increment new & set
        auto oldInd = freq.find(a[ind]);
        if (oldInd->second == 1)
        {
            freq.erase(oldInd);
            if (a[ind] < min) min = a[ind];
        }
        else --(oldInd->second);

        auto newInd = freq.find(val);
        if (newInd == freq.end())
        {
            if (min == val)
            {
                for (std::map<int, int>::iterator it = freq.insert({val, 1}).first; it != freq.end(); ++it)
                {
                    min = it->first + 1;
                    if (freq.find(min) == freq.end()) break;
                }
            }
            else
            {
                freq[val] = 1;
            }
        }
        else ++(newInd->second);

        a[ind] = val;

        std::cout << min << '\n';
    }

    return 0;
}