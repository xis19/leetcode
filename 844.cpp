#include <string>

bool backspaceCompare(std::string& S, std::string& T) {
    // reverse looking
    auto fetch = [](std::string::reverse_iterator& rIter, const std::string::reverse_iterator& end) -> char {
        int backspaceChars = 0;
        while(rIter != end) {
            char ch = *rIter++;
            if (ch == '#') {
                ++backspaceChars;
            } else {
                if (backspaceChars == 0) {
                    return ch;
                }
                --backspaceChars;
            }
        } while(rIter != end);

        return 0;
    };

    auto rSIter = S.rbegin();
    const auto rSEnd = S.rend();
    auto rTIter = T.rbegin();
    const auto rTEnd = T.rend();
    while(true) {
        char s = fetch(rSIter, rSEnd);
        char t = fetch(rTIter, rTEnd);

        if (s != t) return false;
        if (s == 0 && t == 0) return true;
    }
}
