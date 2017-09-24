#include <algorithm>
#include <array>
#include <string>

bool canPermutePalindrome(const std::string& s) {
    std::array<int, 256> chCount;
    std::fill(chCount.begin(), chCount.end(), 0);

    for(auto ch: s) {
        ++chCount[ch];
    }
    return std::count_if(chCount.begin(), chCount.end(), [](int v) { return v & 1; }) < 2;
}
