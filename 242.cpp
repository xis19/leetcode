#include <array>
#include <string>

bool isAnagram(std::string s, std::string t) {
    std::array<int, 26> counter;
    std::fill(counter.begin(), counter.end(), 0);
    for(auto ch: s) ++counter[ch - 'a'];
    for(auto ch: t) --counter[ch - 'a'];
    for(auto i: counter) if (i) return false;
    return true;
}
