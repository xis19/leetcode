#include <string>

std::string longestPalindrome1(const std::string& s) {
    const int LEN = s.length();
    std::string result;
    int maxLen(0);
    for(int start = 0; start < LEN; ++start) {
        int i(0);

        int lengthEven = 0;
        while(start - i >= 0 && start + i + 1 < LEN) {
            if (s[start - i] == s[start + i + 1]) {
                lengthEven += 2;
                ++i;
            } else {
                break;
            }
        }

        int lengthOdd = 1;
        i = 1;
        while(start - i >= 0 && start + i < LEN) {
            if (s[start - i] == s[start + i]) {
                ++i, lengthOdd += 2;
            } else {
                break;
            }
        }

        if (lengthOdd > maxLen && lengthOdd > lengthEven) {
            maxLen = lengthOdd;
            result = s.substr(start - lengthOdd / 2, lengthOdd);
        }
        if (lengthEven > maxLen && lengthEven > lengthOdd) {
            maxLen = lengthEven;
            result = s.substr(start - lengthEven / 2 + 1, lengthEven);
        }
    }
    return result;
}
