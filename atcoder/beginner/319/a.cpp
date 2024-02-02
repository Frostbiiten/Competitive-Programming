#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);

    std::map<std::string, int> ratings = {
        {"tourist", 3858},
        {"ksun48", 3679},
        {"Benq", 3658},
        {"Um_nik", 3648},
        {"apiad", 3638},
        {"Stonefeang", 3630},
        {"ecnerwala", 3613},
        {"mnbvmar", 3555},
        {"newbiedmy", 3516},
        {"semiexp", 3481}
    };
    
    std::string str;
    std::cin >> str;
    std::cout << ratings[str];

    return 0;
}