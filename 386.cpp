#include <vector>

std::vector<int> lexicalOrder(int n) {
    std::vector<int> result;
    if (n <= 0) return result;

    result.reserve(n);

    // Strategy:
    //  Start with 1
    //  Try to multiple the value by 10, if it is larger than n, increase the
    //  value by 1.
    //  If the increased value ends with 0, remove the tailing 0 since xxx0 is
    //  lexically larger than xxx.
    result.push_back(1);
    for(int i = 1; i < n; ++i) {
        int value = result.back();
        if (value * 10 > n) {
            if (value == n) {
                // Situation 1: n = 15, value = 15, next value is 15 / 10 + 1 =
                // 2. Situation 2: n = 19, value = 19, next value is 19 / 10 + 1
                // = 2. So this is the formula
                value /= 10;
                ++value;
            } else {
                ++value;
            }
            // If we reached value like 20, we should collapse to 2 because 2 is
            // lexically smaller than 20.
            while(value % 10 == 0) value /= 10;
        } else {
            value *= 10;
        }
        result.push_back(value);
    }

    return result;
}
