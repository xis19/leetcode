#include <limits>
#include <string>
#include <vector>

std::vector<int> shortestToChar(const std::string& s, const char c) {
    const int LEN = s.length();

    std::vector<int> result(LEN);
    std::fill(result.begin(), result.end(), std::numeric_limits<int>::max());

    for(int i = 0; i < LEN; ++i) {
        if (s[i] == c) {
            result[i] = 0;

            for(int j = i - 1; j >= 0; --j) {
                if (result[j] <= i - j || s[j] == c) break;
                result[j] = i - j;
            }
            for(int j = i + 1; j < LEN; ++j) {
                if (s[j] == c) break;
                result[j] = j - i;
            }
        }
    }

    return result;
}
