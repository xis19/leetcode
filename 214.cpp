#include <algorithm>
#include <string>

std::string shortestPalindrome(std::string s) {
    if (s.size() == 0) return std::string();

    std::string reversed = s;

    std::reverse(reversed.begin(), reversed.end());

    for(auto rI = reversed.begin();rI != reversed.end(); ++rI) {
        if (std::equal(rI, reversed.end(), s.begin())) {
            std::string result(reversed.begin(), rI);
            result += s;
            return result;
        }
    }

    return "";
}
