#include <iostream>
#include <set>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    std::string s;
    std::set<std::string> find{ "ACE", "BDF", "CEG", "DFA", "EGB", "FAC","GBD"};
    std::cin >> s;
    std::cout << (find.count(s) ? "Yes" : "No");

    return 0;
}