#include <array>
#include <string>

bool isIsomorphic(std::string s, std::string t) {
    const int LEN = s.length();

    std::array<int, 256> mapper;
    std::array<int, 256> revMapper;
    std::fill(std::begin(mapper), std::end(mapper), 0);
    std::fill(std::begin(revMapper), std::end(revMapper), 0);

    for(int i = 0; i < LEN; ++i) {
        char cs = s[i], ct = t[i];
        if (!mapper[cs] && !revMapper[ct]) {
            mapper[cs] = ct;
            revMapper[ct] = cs;
        } else {
            if (mapper[cs] != ct || revMapper[ct] != cs) return false;
        }
    }
    return true;
}
