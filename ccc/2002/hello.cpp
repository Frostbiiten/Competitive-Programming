#include <iostream>
#include <stdio.h>
#include <numeric>

using namespace std; 

int main () {
    int a, b;
    scanf("%d\n%d", &a, &b); 

    int first = a / b; 
    int remainder = a % b; 
    int greatestCommonDivisor = gcd(remainder, b); 
    if (remainder == 0) cout << first << endl; 
    else if (first == 0) cout << remainder/greatestCommonDivisor << "/" << b/greatestCommonDivisor << endl; 
    else cout << first << " " << remainder/greatestCommonDivisor << "/" << b/greatestCommonDivisor << endl; 
}