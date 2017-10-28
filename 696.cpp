#include <string>

int countBinarySubstrings(const std::string& s) {
    char currBit = '\0';
    int prevLen(0);
    int currLen(0);
    int result(0);

    for(auto ch: s) {
        if (ch != currBit) {
            prevLen = currLen;
            currLen = 1;
            currBit = ch;
        } else {
            ++currLen;
        }
        if (currLen <= prevLen) ++result;
    }

    return result;
}
