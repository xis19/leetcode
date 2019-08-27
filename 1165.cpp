#include <string>
#include <unordered_map>


int calculateTime(const std::string& keyboard, const std::string& word) {
    std::unordered_map<char, int> index;

    for(int i = 0; i < static_cast<int>(keyboard.size()); ++i) {
        index[keyboard[i]] = i;
    }

    int len = 0;
    int pos = 0;
    for(auto ch: word) {
        int chPos = index[ch];
        len += std::abs(pos - chPos);
        pos = chPos;
    }

    return len;
}
