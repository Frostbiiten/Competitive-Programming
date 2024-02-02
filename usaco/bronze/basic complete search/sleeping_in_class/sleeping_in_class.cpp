// http://usaco.org/index.php?page=viewproblem2&cpid=1203

/* IDEA
Sum must be constant because we are simply combining existing numbers. Therefore, if all
elements are equal, they must be equivalent to sum of original set divided by the size of the
reduced set (this value be div). If div is not an integer, then it is impossible to produce a
a valid reduced set with such a size. However, if it is an integer, we can move on to checking
if it is reproducible. Because addition is commutative, combining n adjacent integers is the same
as repeatedly combining two adjacent ones n - 1 times. Therefore, we can simply sweep through the original
set and attempt to combine integers such that each group is equivalent to div
*/ 

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int t, n;
    std::cin >> t;

    for (int c = 0; c < t; ++c)
    {
        std::cin >> n;
        int a[n], total = 0;

        for (int i = 0; i < n; ++i)
        {
            std::cin >> a[i];
            total += a[i];
        }

        for (int width = n; width > 0; --width)
        {
            int div = total / width;
            if (div * width == total)
            {
                // attempt
                bool good = true;
                for (int i = 0, s = 0; i < n; ++i)
                {
                    s += a[i];
                    if (s == div) s = 0;
                    if (s > div)
                    {
                        good = false;
                        break;
                    }
                }
                if (good)
                {
                    std::cout << n - width << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}