#include <functional>
#include <string>
#include <vector>
#include <unordered_set>

std::vector<std::string> findAllConcatenatedWordsInADict(const std::vector<std::string>& words) {
    std::unordered_set<std::string> wordList(words.begin(), words.end());

    std::function<bool(const std::string&, bool)> canConstruct =
            [&wordList, &canConstruct](const std::string& word, bool includeSelf) -> bool {
        const int LEN = word.size();
        for(int i = 1; i < LEN; ++i) {
            if (wordList.find(word.substr(0, i)) != wordList.end() &&
                    canConstruct(word.substr(i, LEN - i), true)) {
                return true;
            }
        }
        if (includeSelf && wordList.find(word) != wordList.end())
            return true;

        return false;
    };

    std::vector<std::string> result;
    for(auto word: words) {
        if (canConstruct(word, false)) {
            result.push_back(word);
        }
    }

    return result;
}
