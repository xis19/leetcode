#include <string>

std::string countAndSay(int n) {
    if (n == 1) {
        return std::string("1");
    }

    std::string previous = countAndSay(n - 1);
    std::string result;
    char last_ch = previous[0];
    int count = 0;
    for(auto ch: previous) {
        if (ch == last_ch) {
            ++count;
        } else {
            result += std::to_string(count) + last_ch;
            last_ch = ch;
            count = 1;
        }
    }
    result += std::to_string(count) + last_ch;
    return result;
}
