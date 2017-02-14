#include <algorithm>
#include <string>

int firstUniqChar(const std::string& s) {
    int charCount[26];
    std::fill(charCount, charCount + 26, -2);
    for(size_t i = 0; i < s.size(); ++i) {
        char index = s[i] - 'a';
        if (charCount[index] == -2) {
            charCount[index] = i;
        } else if (charCount[index] >= 0) {
            charCount[index] = -1;
        }
    }
    std::sort(charCount, charCount + 26);
    for(auto v: charCount) {
        if (v >= 0) return v;
    }
    return -1;
}
