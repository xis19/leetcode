#include <array>
#include <string>
#include <unordered_set>

int numKLenSubstrNoRepeats(const std::string& S, int K) {
    const int LEN = S.size();
    if (LEN < K) return 0;

    int result(0);

    std::array<int, 26> usedCharCount;
    std::unordered_set<char> usedChars;

    std::fill(usedCharCount.begin(), usedCharCount.end(), 0);
    for (int i = 0; i < K - 1; ++i) {
        const char c = S[i];
        usedChars.insert(c);
        ++usedCharCount[c - 'a'];
    }

    for (int kStart = 0, kEnd = K - 1; kEnd < LEN; ++kEnd, ++kStart) {
        // Append the new character
        char newChar = S[kEnd];
        usedChars.insert(newChar);
        ++usedCharCount[newChar - 'a'];

        // Check if unique
        if (static_cast<int>(usedChars.size()) == K) {
            ++result;
        }

        // pop up the first char
        char lastChar = S[kStart];
        if (usedCharCount[lastChar - 'a'] == 1) {
            usedChars.erase(lastChar);
        }
        --usedCharCount[lastChar - 'a'];
    }

    return result;
}
