#include <string>
#include <vector>

std::vector<std::string> generatePossibleNextMoves(const std::string& s) {
    std::vector<std::string> result;
    const int LEN = s.length();
    if (LEN < 2) return result;

    for(int i = 0; i < LEN - 1; ++i) {
        if (s[i] == '+' && s[i] == s[i + 1]) {
            std::string tmp = s;
            tmp[i] = '-';
            tmp[i + 1] = '-';
            result.emplace_back(tmp);
        }
    }
    return result;
}
