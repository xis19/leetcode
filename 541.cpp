#include <algorithm>
#include <string>

std::string reverseStr(const std::string& s, int k) {
    std::string result(s);

    std::string::iterator reverseStart = result.begin();
    std::string::iterator reverseEnd = result.begin();
    bool reverse = true;
    for(int c = 0; reverseEnd != result.end(); ++c, ++reverseEnd) {
        if (c == k) {
            if (reverse) {
                std::reverse(reverseStart, reverseEnd);
            }
            reverseStart = reverseEnd;
            reverse = !reverse;
            c = 0;
        }
    }
    if (reverseStart != result.end() && reverse)
        std::reverse(reverseStart, reverseEnd);

    return result;
}
