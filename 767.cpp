#include <algorithm>
#include <array>
#include <string>
#include <vector>
#include <utility>

std::string reorganizeString(const std::string& S) {
    const int LEN = S.length();

    // First count character/count, pick up the character with most count
    std::vector<std::pair<char, int>> chList(26, std::make_pair(0, 0));
    for(auto ch: S) chList[ch - 'a'].first = ch, ++chList[ch - 'a'].second;
    std::sort(chList.begin(), chList.end(),
        [](std::pair<char, int>& l, std::pair<char, int>& r) {
            return l.second > r.second;
        }
    );

    if (chList.front().second > (LEN + 1) / 2) {
        return "";
    }

    std::string result(LEN, 0);
    int chIndex = 0;
    int chCount = 0;
    int resultIndex = 0;
    while(chIndex < 26) {
        if (chCount >= chList[chIndex].second) {
            ++chIndex;
            chCount = 0;
            continue;
        }
        result[resultIndex] = chList[chIndex].first;
        resultIndex += 2;
        ++chCount;
        if (resultIndex >= LEN) {
            // We filled all even positions, now fill odd positions
            resultIndex = 1;
        }
    }

    return result;
}
