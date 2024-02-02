#include <iostream>

int main()
{
    int k;
    std::cin >> k;

    std::string r;
    int m = std::min(10, k);
    r = std::to_string(m);
    k -= m;


    while(k--)
    {
        ++r[r.size() - 1];
        int ind = r.size();
        for (int i = r.size() - 2; i >= 0; --i)
        {
            if (r[i] <= r[i + 1])
            {
                ++r[i];
                ind = i + 1;
            }

            if (r[i] > '9')
            {
                r = (char)('0' + (r.size() - 1)) + r;
                ind = i;
            }
        }

        for (int i = r.size() - 1, c = 0; i >= ind; --i, ++c)
        {
            r[i] = '0' + c;
        }
    }
    

    std::cout << r << '\n';
    return 0;
}