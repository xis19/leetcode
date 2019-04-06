#include <vector>

std::vector<bool> prefixesDivBy5(const std::vector<int>& A) {
    std::vector<bool> result;
    // The point is we only care the last digit in dec. If it is 0 or 5, we
    // yield true; otherwise false.
    int value = 0;

    for(const auto& v: A) {
        value <<= 1;
        value += v;
        result.push_back(value % 5 == 0);
        value %= 10;
    }
    return result;
}
