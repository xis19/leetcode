#include <algorithm>
#include <string>
#include <unordered_map>


std::string customSortString(const std::string& S, std::string T) {
    const int S_LEN = S.size();
    std::string sortedS(S);

    std::sort(sortedS.begin(), sortedS.end());

    std::unordered_map<char, char> customToOriginal, originalToCustom;
    for(int i = 0; i < S_LEN; ++i) {
        customToOriginal[S[i]] = sortedS[i];
        originalToCustom[sortedS[i]] = S[i];
    }

    std::transform(
        T.begin(), T.end(),
        T.begin(),
        [&](char c) -> char {
            if (customToOriginal.find(c) != customToOriginal.end()) {
                return customToOriginal[c];
            }
            return c;
        }
    );

    std::sort(T.begin(), T.end());

    std::transform(
        T.begin(), T.end(),
        T.begin(),
        [&](char c) -> char {
            if (originalToCustom.find(c) != originalToCustom.end()) {
                return originalToCustom[c];
            }
            return c;
        }
    );

    return T;
}
