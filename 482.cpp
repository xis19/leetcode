#include <cctype>
#include <string>

std::string licenseKeyFormatting(std::string S, int K) {
    std::string result;
    int block = 0;
    for(auto rI = S.rbegin(); rI != S.rend(); ++rI) {
        if (*rI == '-') {
            continue;
        }
        if (block == K) {
            block = 0;
            result.push_back('-');
        }
        result.push_back(std::toupper(*rI));
        ++block;
    }
    return std::string(result.rbegin(), result.rend());
}
