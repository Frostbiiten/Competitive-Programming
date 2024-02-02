#include <bitset>
#include <fstream>
#include <iostream>
#include <algorithm> 

int main()
{
    std::string sequence = "AAGAATTCGCCAGAGTCTTGCTATGGACCTCAAGGTAGTGGCCAATACCGGGCCATGAATTCCGATACG";
    std::string complementary;
    complementary.resize(sequence.size());

    for (int i = 0; i < sequence.size(); ++i)
    {
        char c = sequence[i];
        if (c == 'G') c = 'C';
        else if (c == 'C') c = 'G';
        else if (c == 'A') c = 'T';
        else c = 'A';

        complementary[complementary.size() - 1 - i] = c;
    }

    // reverse and slide check
    std::string reverse = sequence;
    std::reverse(reverse.begin(), reverse.end());

    int count = 0;
    for (int offset = 0; offset < sequence.size(); ++offset)
    {
        int lenA = 0; int lenB = 0;
        for (int i = 0; i < sequence.size() - offset; ++i)
        {
            if (sequence[i] == reverse[i + offset])
            {
                ++lenA;
            }
            else
            {
                if (lenA >= 4)
                {
                    lenA -= 3;
                    count += (lenA * (lenA + 1)) >> 1;
                }

                lenA = 0;
            }

            if (sequence[i + offset] == reverse[i])
            {
                ++lenB;
            }
            else
            {
                if (lenB >= 4)
                {
                    count += (lenA * (lenA + 1)) >> 1;
                    lenB -= 3;
                }

                lenB = 0;
            }
        }
    }

    std::cout << count << '\n';
}