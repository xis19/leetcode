#include <string>

int countSubstrings(const std::string& s) {
    const int LEN = s.size();
    int count(0);
    for(int i = 0; i < LEN * 2 - 1; ++i) {
        int v = i >> 1;
        if ((i & 1) == 0) {   // we locate at a character
            ++count;    // single c
            for(int l = 1; l <= v; ++l, ++count) {
                if (s[v - l] != s[v + l]) break;
            }
        } else {            // we locate between characters
            for(int l = 0; l <= v; ++l, ++count) {
                if (s[v - l] != s[v + l + 1]) break;
            }
        }
    }
    return count;
}
