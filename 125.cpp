#include <cctype>
#include <string>

bool isPalindrome(const std::string& s) {
    if (s.empty()) {
        return true;
    }

    auto lIter = std::begin(s);
    auto rIter = std::prev(std::end(s));
    while(lIter < rIter) {
        while(!std::isalnum(*lIter) && lIter < rIter) ++lIter;
        while(!std::isalnum(*rIter) && lIter < rIter) --rIter;
        if (std::tolower(*lIter) != std::tolower(*rIter)) {
            return false;
        }
        ++lIter, --rIter;
    }
    return true;
}
