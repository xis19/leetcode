#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

bool isAlienSorted(std::vector<std::string>& words, const std::string& order) {
    const int ORDER_LENGTH = order.length();
    std::unordered_map<char, int> mapper;
    for(int i = 0; i < ORDER_LENGTH; ++i) {
        mapper[order[i]] = i;
    }

    for(auto& w: words) {
        std::transform(w.begin(), w.end(), w.begin(), [&mapper](char ch) -> char { return mapper[ch]; });
    }

    std::string prevWord = "";
    for(const auto& w: words) {
        if (w < prevWord) return false;
        prevWord = w;
    }

    return true;
}
