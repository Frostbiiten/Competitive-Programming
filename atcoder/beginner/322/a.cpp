#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n; std::string s;
    std::cin >> n >> s;
    auto search = s.find("ABC");

    if (search == std::string::npos) std::cout << "-1";
    else std::cout << search + 1<< '\n';

    return 0;
}