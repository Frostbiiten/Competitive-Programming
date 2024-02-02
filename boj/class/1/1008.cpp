// https://www.acmicpc.net/problem/1008
#include <iostream>
#include <iomanip>

int main()
{
    double a, b;
    std::cin >> a >> b;
    std::cout << std::setprecision(15) << a / b << '\n';
}