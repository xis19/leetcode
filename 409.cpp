#include <string>
#include <unordered_map>

int longestPalindrome(const std::string& s) {
    std::unordered_map<char, int> values;
    for(auto ch: s) ++values[ch];

    int result(0);
    int hasOdd(false);
    for(auto kvpair: values) {
        if (kvpair.second % 2) {
            if (hasOdd) {
                result += kvpair.second - 1;
            } else {
                result += kvpair.second;
                hasOdd = true;
            }
        } else {
            result += kvpair.second;
        }
    }

    return result;
}

