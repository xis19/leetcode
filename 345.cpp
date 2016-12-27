#include <string>

std::string reverseVowels(const std::string& s) {
    std::string result(s);
    std::string::iterator lIter = std::begin(result), rIter = std::end(result) - 1;
    auto isVowel = [&](char ch) -> bool {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    };
    while(lIter < rIter) {
        while(!isVowel(*lIter) && lIter < rIter) ++lIter;
        while(!isVowel(*rIter) && rIter > lIter) --rIter;
        std::swap(*lIter, *rIter);
        ++lIter; --rIter;
    }
    return result;
}
