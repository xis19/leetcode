#include <string>

int monotoneIncreasingDigits(int N) {
    std::string s = std::to_string(N);
    char minSoFar = '9' + 1;
    int len = s.size();
    for (int i = len - 1; i >= 0; --i) {
        if (s[i] > minSoFar) {
            s[i] -= 1;
            for (int j = i + 1; j < len; ++j) {
                s[j] = '9';
            }
            minSoFar = s[i];
        } else {
            minSoFar = std::min(minSoFar, s[i]);
        }
    }

    int firstNonZero = 0;
    while (s[firstNonZero] == '0') ++firstNonZero;
    return std::stoi(s.substr(firstNonZero));
}
