#include <stack>
#include <string>
#include <vector>


std::vector<std::string> letterCasePermutation(const std::string& s) {
    auto flip = [](char& ch) {
        if (ch >= 'A' && ch <= 'Z') {
            ch += 'a' - 'A';
        } else {
            ch -= 'a' - 'A';
        }
    };

    const int LEN = s.length();
    std::vector<int> positions;
    for(int i = 0; i < LEN; ++i) {
        char ch = s[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            // Consider i = 0 situation
            positions.push_back(i + 1);
        }
    }

    const int PSIZE = positions.size();
    std::string ss(s);
    std::vector<std::string> result;
    auto nextState = [&]() -> bool {
        for(int i = PSIZE - 1; i >= 0; --i) {
            if (positions[i] > 0) {
                flip(ss[std::abs(positions[i]) - 1]);
                positions[i] *= -1;
                for(int j = i + 1; j < PSIZE; ++j) {
                    flip(ss[std::abs(positions[j]) - 1]);
                    positions[j] *= -1;
                }
                result.push_back(ss);
                return true;
            }
        }
        return false;
    };

    result.push_back(ss);
    while(nextState());
    return result;
}
