#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0), std::cout.tie(0);
    int ans[6] = {1, 3, 2, 6, 4, 5};
    int n;
    std::cin >> n;
    std::cout << ans[n % 6];
    return 0;
}