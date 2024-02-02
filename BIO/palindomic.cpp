#include <iostream>
#include <vector>

int main()
{
    std::string seq;
    std::cin >> seq;

    std::vector<int> processed;
    processed.reserve(seq.size());
    for (int i = 0; i < seq.size(); ++i)
    {
        int val;
        switch (seq[i])
        {
            case 'A':
                val = 1;
                break;

            case 'T':
                val = -1;
                break;

            case 'C':
                val = 2;
                break;

            case 'G':
                val = -2;
                break;
        }

        processed.push_back(val);
    }

    for (int i = 0; i < processed.size() - 1; ++i)
    {
        int l, r;
        int offset = -1;

        do 
        {
            ++offset;
            if (i - offset < 0 || i + 1 + offset >= processed.size())
            {
                --offset;
                break;
            }

            l = processed[i - offset];
            r = processed[i + 1 + offset];
        }
        while (l == -r);

        // print sequence if detected
        if (offset > 1)
        {
            for (int j = i - offset + 1; j < i + 1 + offset; ++j) std::cout << seq[j];
            std::cout << '\n';
        }
    }
}