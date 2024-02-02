// not working
// https://codeforces.com/contest/977/problem/C

#include <iostream>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;
    int a[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
    }

    std::sort(a, a + n);
    if (k == 0)
    {
        if (a[0] > 1) std::cout << "1\n";
        else std::cout << "-1\n";
    }
    else if (k == n)
    {
        if (a[n - 1] < 1000000000) std::cout << "1000000000\n";
        else std::cout << "-1\n";
    }
    else
    {
        int min = a[k - 1];
        int max = a[k];
    
        if(min < max) std::cout << min << '\n';
        else std::cout << "-1\n";
    }

    return 0;
}