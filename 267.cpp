#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> generatePalindromes(const std::string& s) {
    std::vector<std::string> result;

    std::unordered_map<char, int> chCount;
    for(auto ch: s) {
        if (chCount.find(ch) == chCount.end()) chCount[ch] = 0;
        ++chCount[ch];
    }

    char evenChar = 0;
    std::string semi;
    for (auto& item: chCount) {
        if (item.second % 2 == 1) {
            if (evenChar != 0) {
                return result;
            }
            evenChar = item.first;
            --item.second;
        }
        item.second /= 2;
        for (int i = 0; i < item.second; ++i) {
            semi.push_back(item.first);
        }
    }
    std::sort(semi.begin(), semi.end());

    do {
        result.push_back(semi);
        if (evenChar != 0) result.back() += evenChar;
        std::copy(semi.rbegin(), semi.rend(), std::back_inserter(result.back()));
    } while(std::next_permutation(semi.begin(), semi.end()));

    return result;
}
