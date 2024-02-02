#include <iostream>
#include <stdint.h>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        uint64_t n, k, newIndex;
        std::cin >> n >> k;

        int origk;
        origk = k;
        uint64_t partition = n;
        bool t = true;

        int iterations = 0;
        while (true) //*
        {
            uint64_t div = k / 2;
            if (t == (div * 2 == k))
            {
                //std::cout << n - partition + div << ' ' << ((iterations & 1) && ((n & 1) != (k & 1))) << '\n';
                uint64_t p = (2 << iterations);
                uint64_t offset = (n * (p - 1)) / p;
                //bool plus = (iterations & 1) && ((n & 1) != (origk & 1));
                std::cout << n - partition + div << '\n';
                break;
            }   

            k = div;
            if (!(n & 1)) t = !t;
            
            //partition -= (partition + 1) / 2;
            //partition -= (partition + 1) / 2;
            ++iterations;
        }
    }

    return 0;
}