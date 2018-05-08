#include <string>
#include <vector>


std::vector<std::vector<int>> largeGroupPositions(const std::string& S) {
    const int LEN = S.size();
    std::vector<std::vector<int>> result;

    char last(0);
    int count(0);
    for(int i = 0; i < LEN; ++i) {
        char ch = S[i];
        if (ch == last) {
            ++count;
        } else {
            if (count >= 3) {
                result.push_back(std::vector<int>{i - count, i - 1});
            }
            count = 1;
        }
        last = ch;
    }

    if (count >= 3) {
        result.push_back(std::vector<int>{LEN - count, LEN - 1});
    }

    return result;
}
