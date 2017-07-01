#include <vector>

std::vector<int> getRow(int rowIndex) {
    const int LEN = rowIndex + 1;

    std::vector<int> result(LEN);
    std::fill(result.begin(), result.end(), 0);
    result.back() = 1;

    for(int row = 2; row <= LEN; ++row) {
        int oldValue = 1;
        for(int i = LEN - 2; i > LEN - row; --i) {
            int newValue = result[i] + oldValue;
            oldValue = result[i];
            result[i] = newValue;
        }
        result[LEN - row] = 1;
    }

    return result;
}
