// https://www.acmicpc.net/problem/1000
#include <iostream>
#include <string>

int main()
{
    int n = 1;
    std::string s;
    std::getline(std::cin, s);
    for (int i = 0; i < s.size(); ++i) n += (s[i] == ' ');
    std::cout << n << '\n';
}