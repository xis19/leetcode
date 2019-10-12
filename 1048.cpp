#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

int longestStrChain(std::vector<std::string>& words) {
    const int NUM_WORDS = words.size();

    std::unordered_map<std::string, int> wordMap;
    // Sort the words by the order of the length, so we could remove character
    // to find next element
    std::sort(words.begin(), words.end(),
        [](const std::string& w1, const std::string& w2) {
            return w1.length() > w2.length();
        });
    for (int i = 0; i < NUM_WORDS; ++i) {
        wordMap[words[i]] = i;
    }

    // The word itself constitutes a chain with length 1.
    std::vector<int> length(NUM_WORDS, 1);
    int maxLen(0);
    for (int i = 0; i < NUM_WORDS; ++i) {
        maxLen = std::max(length[i], maxLen);

        // Remove 1 character, see if they are in the list
        const std::string& WORD = words[i];
        const int WORD_LEN = WORD.length();
        for (int j = 0; j < WORD_LEN; ++j) {
            const std::string W = WORD.substr(0, j) +
                                  WORD.substr(j + 1, WORD_LEN);
            const auto wIter= wordMap.find(W);
            if (wIter != wordMap.end()) {
                length[wIter->second] = std::max(
                    length[wIter->second],
                    length[i] + 1
                );
            }
        }
    }

    return maxLen;
}
