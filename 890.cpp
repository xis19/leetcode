#include <unordered_map>
#include <vector>

std::vector<std::string> findAndReplacePattern(const std::vector<std::string>& words, const std::string& pattern) {
    const int PATTERN_LENGTH = pattern.size();

    std::vector<std::string> result;
    for(const auto& word: words) {
        if (word.size() != pattern.size()) {
            continue;
        }

        bool match = true;
        std::unordered_map<char, char> pwMap;
        std::unordered_map<char, char> wpMap;
        for(int i = 0; i < PATTERN_LENGTH; ++i) {
            const char P = pattern[i];
            const char W = word[i];
            auto pwMapFind = pwMap.find(P);
            auto wpMapFind = wpMap.find(W);
            if (pwMapFind == pwMap.end() && wpMapFind == wpMap.end()) {
                pwMap[P] = W;
                wpMap[W] = P;
                continue;
            } else if (pwMapFind != pwMap.end() && wpMapFind != wpMap.end() && pwMap[P] == W) {
                continue;
            } else {
                match = false;
                break;
            }
        }

        if (match) {
            result.push_back(word);
        }
    }

    return result;
}
