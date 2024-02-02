#include <iostream>

int main()
{
    std::cin.tie(0); std::cout.tie(0); std::ios_base::sync_with_stdio(0);
    int len; std::string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    std::cin >> len;
    std::cout << pi.substr(0, len + 2) << '\n';
}