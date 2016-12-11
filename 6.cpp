#include <string>

std::string convert(std::string s, int numRows) {
    int blockLength = numRows * 2 - 2;
    if (blockLength <= 1) {
        return std::string(s);
    }

    std::string result;

    for(int r = 0; r < numRows; ++r) {
        for(size_t i = 0; i < s.length(); i += blockLength) {
            if (i + r < s.length())
                result += s[i + r];
            if (r != 0 && r != numRows - 1 && i + blockLength - r < s.length()) {
                result += s[i + blockLength - r];
            }
        }
    }

    return result;
}

