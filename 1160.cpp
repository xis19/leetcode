#include <string>
#include <unordered_map>
#include <vector>

int countCharacers(const std::vector<std::string>& words, const std::string& chars) {
    auto countChars = [](const std::string& str) {
        std::unordered_map<char, int> wc;
        for (auto ch: str) {
            if (wc.find(ch) == wc.end()) wc[ch] = 0;
            ++wc[ch];
        }
        return wc;
    };

    auto charsCount = countChars(chars);

    int result(0);
    for(auto& w: words) {
        auto wordCharsCount = countChars(w);
        bool covered = true;
        for(auto ch = 'a'; ch <= 'z'; ++ch) {
            if (wordCharsCount.find(ch) != wordCharsCount.end()) {
                if (charsCount.find(ch) == charsCount.end() ||
                        charsCount[ch] < wordCharsCount[ch]) {
                    covered = false;
                    break;
                }
            }
        }
        if (covered) result += w.size();
    }

    return result;
}
