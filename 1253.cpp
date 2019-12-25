#include <vector>

std::vector<std::vector<int>> reconstructMatrix(int upper, int lower, std::vector<int>& colsum) {
    // We MUST place all 2 for colsum first. Then we are free to place all 1s in colusm.
    const int LEN = colsum.size();
    std::vector<std::vector<int>> result(2, std::vector<int>(LEN, 0));

    for (int i = 0; i < LEN; ++i) {
        if (colsum[i] == 2) {
            result[0][i] = result[1][i] = 1;
            --upper;
            --lower;
        }
    }

    for (int i = 0; i < LEN; ++i) {
        if (colsum[i] == 1) {
            if (upper > 0) {
                result[0][i] = 1;
                --upper;
            } else {
                result[1][i] = 1;
                --lower;
            }
        }
    }

    if (upper != 0 || lower != 0) {
        return {};
    }

    return result;
}
