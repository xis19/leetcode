#include <string>
#include <vector>

std::string shiftingLetters(const std::string& S, std::vector<int>& shifts) {
    const int LEN = shifts.size();

    std::string result(S);

    int last = 0;
    for (auto rs = shifts.rbegin(); rs != shifts.rend(); ++rs) {
        *rs += last;
        *rs %= 26;
        last = *rs;
    }

    for (int i = 0; i < LEN; ++i) {
        result[i] = (result[i] - 'a' + shifts[i]) % 26 + 'a';
    }

    return result;
}
