#include <iostream>
#include <cstring>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);

    int n, q;
    std::cin >> n >> q;

    std::int64_t x, v;
    std::pair<std::int64_t, int> arr[n];
    memset(arr, 0, sizeof(arr));

    int instr, l, r;
    for (int test = 0; test < q; ++test)
    {
        std::cin >> instr >> l;
        --l;

        if (instr == 3)
        {
            //std::cout << arr[l] << '\n';
            continue;
        }

        std::cin >> r >> x >> v;
        --r;

        if (instr == 1)
        {
            for (int i = l; i <= r; i += x)
            {
                //arr[i] += v;
            }
        }
        else
        {
            for (int i = l; i <= r; i += x)
            {
                arr[i] = {v, test};
            }
        }
    }

    return 0;
}