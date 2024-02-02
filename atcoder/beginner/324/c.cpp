#include <ios>
#include <vector>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    int n;
    std::string orig, current;
    std::cin >> n;
    std::cin >> orig;

    std::vector<int> ind;
    ind.reserve(n);

    for (int str = 0; str < n; ++str)
    {
        std::cin >> current;

        if (orig.size() == current.size())
        {
            if (orig == current)
            {
                // equal
                ind.push_back(str);
            }
            else
            {
                int count = 0;
                bool valid = true;
                for (int j = 0; j < current.size(); ++j)
                {
                    if (current[j] != orig[j])
                    {
                        if (count)
                        {
                            valid = false;
                            break;
                        }
                        ++count;
                    }
                }

                if (valid) ind.push_back(str);
            }
        }
        else if (current.size() == orig.size() - 1)
        {
            bool valid = true;

            // removal
            int offset = 0;
            for (int i = 0; i < orig.size(); ++i)
            {
                if (orig[i + offset] != current[i])
                {
                    if (offset)
                    {
                        valid = false;
                        break;
                    }
                    ++offset;
                    --i;
                }
            }

            if (valid && offset) ind.push_back(str);
        }
        else if (current.size() == orig.size() + 1)
        {
            bool valid = true;

            // insertion
            int offset = 0;
            for (int i = 0; i < current.size(); ++i)
            {
                if (orig[i] != current[i + offset])
                {
                    if (offset)
                    {
                        valid = false;
                        break;
                    }
                    ++offset;
                    --i;
                }
            }

            if (valid && offset) ind.push_back(str);
        }
    }

    std::cout << ind.size() << '\n';
    for (int i = 0; i < ind.size(); ++i)
    {
        std::cout << ind[i] + 1 << ' ';
    }
    std::cout << '\n';
}