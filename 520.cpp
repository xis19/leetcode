#include <string>

bool detectCaptialUse(const std::string& word) {
    size_t nCapitals(0);
    for(auto ch: word) {
        nCapitals += (ch >= 'A' && ch <= 'Z');
    }
    if (nCapitals == word.size()) {
        return true;
    } else if (nCapitals == 1 && word[0] >= 'A' && word[0] <= 'Z') {
        return true;
    } else if (nCapitals == 0) {
        return true;
    } else {
        return false;
    }
}
