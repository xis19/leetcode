#include <vector>

std::vector<int> constructArray(int n, int k) {
    // The array could be constructed like this:
    //  Let's say n = 5
    //
    //  k = 1
    //
    //  1 2 3 4 5
    //
    //  k = 2
    //
    //  1 5 4 3 2
    //
    //  k = 3
    //
    //  1 5 2 3 4
    //
    //  k = 4
    //
    //  1 5 2 4 3
    std::vector<int> result(n, 0);
    int iter(0), hi(n), lo(1);

    for (int i = 0; i < k - 1; ++i) {
        if (i % 2 == 0) {
            result[iter++] = lo++;
        } else {
            result[iter++] = hi--;
        }
    }
    if (k % 2 == 0) {
        for (int i = hi; i >= lo; --i) result[iter++] = i;
    } else {
        for (int i = lo; i <= hi; ++i) result[iter++] = i;
    }

    return result;
}
