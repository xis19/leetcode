// This is an obvious problem, yet it timed out
/*
    def num_matching_subseq(s, words)
      words.map { |word|
        i, j = 0, 0
        while i < s.length && j < word.length
          j += 1 if s[i] == word[j]
          i += 1
        end
        j == word.length ? 1 : 0
      }.reduce(:+)
    end
*/

#include <array>
#include <string>
#include <vector>

int numMatchingSubseq(const std::string& S, const std::vector<std::string>& words) {
    std::array<std::vector<int>, 26> charMap;
    for(int i = 0; i < static_cast<int>(S.size()); ++i) {
        charMap[S[i] - 'a'].push_back(i);
    }

    int result(0);
    for(const auto& word: words) {
        int i = 0;
        bool match = true;
        for(auto ch: word) {
            auto& charVector = charMap[ch - 'a'];
            auto found = std::lower_bound(
                charVector.begin(),
                charVector.end(),
                i
            );
            if (found == charVector.end()) {
                match = false;
                break;
            }
            i = *found + 1;
        }
        result += match;
    }

    return result;
}
