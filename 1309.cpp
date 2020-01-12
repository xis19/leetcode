#include <algorithm>
#include <cctype>
#include <string>

std::string freqAlphabets(const std::string s) {
    std::string result;
    auto r = s.rbegin();
    while(r != s.rend()) {
        if (std::isdigit(*r)) {
            result.push_back('a' - '1' + *r);
        } else {
            int v = 0;
            v += *++r - '0';
            v += 10 * (*++r - '0');
            result.push_back('a' + v - 1);
        }
        ++r;
    }
    std::reverse(result.begin(), result.end());
    return result;
}
