#include <functional>
#include <limits>
#include <string>
#include <unordered_map>

std::string minWindow(const std::string& s, const std::string& t) {
    const int LEN_S = s.size();
    const int LEN_T = t.size();

    std::unordered_map<char, int> tCount;
    for(auto ch: t) {
        if (tCount.count(ch) == 0)
            tCount[ch] = 0;
        ++tCount[ch];
    }

    if (LEN_S < LEN_T) {
        return "";
    }

    // The idea is:
    //
    //
    //  ADOBECODEBANC
    //    ^
    //    Head
    //  ^
    //  Tail
    //
    // Each time we move Head for one step, and move tail until the string
    // in the range cannot hold all strings in T
    int start = 0;
    bool fulfilled = false;
    int longest = std::numeric_limits<int>::max();
    std::pair<int, int> range;
    for(int end = 1; end <= LEN_S; ++end) {
        char ch = s[end - 1];
        if (tCount.count(ch) == 0) continue;
        --tCount[ch];
        if (tCount[ch] <= 0) {
            // Possible a shortest string
            fulfilled = true;
            for(auto pair: tCount) {
                if (pair.second > 0) {
                    fulfilled = false;
                    break;
                }
            }

            if (!fulfilled) {
                continue;
            }

            while(fulfilled && start <= end - 1) {
                if (end - start < longest) {
                    longest = end - start;
                    range = std::make_pair(start, end);
                }

                char chs = s[start++];
                if (tCount.count(chs) == 0) continue;
                ++tCount[chs];
                if (tCount[chs] > 0) fulfilled = false;
            }
        }
    }

    std::string result;
    for(int i = range.first; i < range.second; ++i) {
        result.push_back(s[i]);
    }

    return result;
}
