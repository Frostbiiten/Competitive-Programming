#include <iostream>

// use psa? (1G memory limit)
int arr[10000000];
int psa[10000001];

int main()
{
    int n, c;
    std::cin >> n >> c;

    int current;
    for (int i = 0; i < n; ++i)
    {
        std::cin >> current;
        ++arr[current];
    }

    // generate psa (maybe use same array)
    for (int i = 1; i < c; ++i)
    {
        psa[i] = arr[i] + psa[i - 1];
    }

    for (int i = 0; i < c; ++i)
    {
        if (arr[i])
        {
            int start = arr[i];

            // start counting from half + 1
        }
    }


    return 0;
}
