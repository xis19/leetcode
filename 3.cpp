#include <algorithm>
#include <array>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    int longestStartPosition = -1;
    int longest = 0;
    std::array<int, 256> lastOccurrence;
    std::fill(std::begin(lastOccurrence), std::end(lastOccurrence), -1);

    for(int index = 0; index < static_cast<int>(s.length()); ++index) {
        char ch = s[index];
        longestStartPosition = std::max(lastOccurrence[ch], longestStartPosition);
        longest = std::max(index - longestStartPosition, longest);
        lastOccurrence[ch] = index;
    }

    return longest;
}

