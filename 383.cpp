#include <string>
#include <unordered_map>

bool canConstruct(const std::string& ransomNote, const std::string& magazine) {
    std::unordered_map<char, int> m;
    for(auto ch: magazine) ++m[ch];
    for(auto ch: ransomNote) --m[ch];
    for(auto kvpair: m) if (kvpair.second < 0) return false;
    return true;
}
