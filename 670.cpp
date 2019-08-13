#include <array>
#include <string>


int maximumSwap(int num) {
    // For each number, swap it with the first number (from left to right) that
    // is smaller than it
    std::string sNum(std::to_string(num));
    const int LEN = sNum.size();

    // For each i, we record the index of first number that is smaller than it.
    std::array<int, 10> firstSmaller;
    std::fill(firstSmaller.begin(), firstSmaller.end(), -1);

    std::string max = sNum;
    for (int i = 0; i < LEN; ++i) {
        int v = sNum[i] - '0';
        if (firstSmaller[v] != -1) {
            // There is a number that smaller than the value, we swap and
            // compare
            std::string t = sNum;
            std::swap(t[i], t[firstSmaller[v]]);
            max = std::max(max, t);
        } else {
            for (int k = v + 1; k <= 9; ++k) {
                if (firstSmaller[k] == -1) {
                    firstSmaller[k] = i;
                } else {
                    break;
                }
            }
        }
    }

    return std::stoi(max);
}
