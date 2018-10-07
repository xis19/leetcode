#include <cctype>
#include <string>

std::string reverseOnlyLetters(std::string S) {
    auto lIter = S.begin();
    auto rIter = S.end() - 1;

    while(lIter < rIter) {
        while(!std::isalpha(*lIter) && lIter < rIter) ++lIter;
        while(!std::isalpha(*rIter) && lIter < rIter) --rIter;

        std::swap(*lIter++, *rIter--);
    }

    return S;
}
