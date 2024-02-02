#include <iostream>
#include <set>

int main()
{
    int n, q;
    std::cin >> n >> q;

    int freq[n + 1];
    memset(freq, 0, sizeof(freq));

    int curr;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> curr;
        ++freq[curr];
    }

    std::set<int> zeros;
    for (int z = 0; z <= n; ++z)
    {
        if (!freq[z]) zeros.insert(z);
    }

    int ind, val;
    for (int query = 0; query < q; ++query)
    {
        std::cin >> ind >> val;
        --ind;

        
    }


    return 0;
}