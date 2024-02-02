#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::cin >> n;
    n -= 45;

    if (n % 90 == 0) std::cout << "Let's go Bob!\n";
    else std::cout << "Rip Bob!\n";

    return 0;
}