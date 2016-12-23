#include <functional>
#include <string>

bool isMatch(const std::string& str, const std::string& regexp) {
    const int strLen = str.length();
    const int regexpLen = regexp.length();

    std::function<bool(int, int)> check = [&](int strIter, int regexpIter) -> bool {
        if (regexpIter == regexpLen)
            return strIter == strLen;

        char regexpChar = regexp[regexpIter];
        char controlChar = (regexpIter + 1 == regexpLen) ? 0 : regexp[regexpIter + 1];

        if (controlChar != '*') {
            // single char match
            if (regexpChar == '.')
                return check(strIter + 1, regexpIter + 1);
            else
                return str[strIter] == regexpChar && check(strIter + 1, regexpIter + 1);
        } else {
            int maxMatchIter = strIter;
            if (regexpChar == '.') {
                maxMatchIter = strLen;
            } else {
                while(regexpChar == str[maxMatchIter]) ++maxMatchIter;
            }
            for(; maxMatchIter >= strIter; --maxMatchIter) {
                if (check(maxMatchIter, regexpIter + 2))
                    return true;
            }
            return false;
        }
    };

    return check(0, 0);
}


#include <iostream>
int main() {
    std::string text;
    std::string regex;
    while(std::cin >> text >> regex) {
        std::cout << isMatch(text, regex) << std::endl;
    }
}
