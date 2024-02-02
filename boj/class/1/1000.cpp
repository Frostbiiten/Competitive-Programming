// https://www.acmicpc.net/problem/1008
#include <iostream>
#include <string>

int main()
{
    int n = 0; bool l = false; std::string s;
    std::getline(std::cin, s);
    s = ' ' + s + ' ';

    for (int i = 0; i < s.size(); ++i)
    {
        bool c = s[i] != ' ';
        n += l != c;
        l = c;
    }

    std::cout << (n >> 1) << '\n';
}