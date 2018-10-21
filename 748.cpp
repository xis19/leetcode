#include <algorithm>
#include <array>
#include <string>
#include <vector>


std::string shortestCompletingWord(const std::string& licensePlate, std::vector<std::string>& words) {
    std::array<int, 26> plateChars;
    std::fill(plateChars.begin(), plateChars.end(), 0);
    for(auto ch: licensePlate) {
        if (std::isalpha(ch)) ++plateChars[std::tolower(ch) - 'a'];
    }

    std::string result;
    for(auto word: words) {
        if (result.size() > 0 && word.size() >= result.size()) continue;

        std::array<int, 26> chars;
        std::fill(chars.begin(), chars.end(), 0);
        for(auto ch: word) {
            if (std::isalpha(ch)) ++chars[std::tolower(ch) - 'a'];
        }

        bool cover = true;
        for(int i = 0; i < 26; ++i) {
            if (chars[i] < plateChars[i]) {
                cover = false;
                break;
            }
        }

        if (cover) result = word;
    }

    return result;
}
