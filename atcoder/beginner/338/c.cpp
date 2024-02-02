#include <iostream>

int main()
{
    //std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    int q[n];
    int a[n];
    int b[n];

    std::cin >> n;

    // scan ingredients
    for (int i = 0; i < n; ++i) std::cin >> q[i];

    // maximum number of dishes that could be made if only A are made
    int maxA = INT_MAX;

    // scan A, get max possible
    for (int i = 0; i < n; ++i)
    {
        std::cin >> a[i];
        maxA = std::min(maxA, q[i] / a[i]);
    }

    // scan B
    for (int i = 0; i < n; ++i)
    {
        std::cin >> b[i];
    }

    // initial B
    int initialB = INT_MAX;

    // get excess for each ingredient
    int excess[n];
    for (int i = 0; i < n; ++i)
    {
        excess[i] = q[i] - a[i] * maxA;
        initialB = std::min(initialB, excess[i] / b[i]);
    }

    // initial best
    int best = initialB + maxA;

    // *** i have a feeling that every one dish A that is removed,
    // you gain ingredients but there is some sort of rate limiter?

    // start with all, A, continuously keep track of excess
    for (int aDishes = maxA; aDishes >= 0; --aDishes)
    {
        for (int i = 0; i < n; ++i)
        {

        }
    }
    
    return 0;
}