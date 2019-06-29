#include <vector>

int numSubarrayBoundedMax(const std::vector<int>& A, int L, int R) {
    // Record the last value larger than R (lastR) and last value between L and
    // R (lastBetween).

    const int LEN = A.size();
    int result = 0;
    int lastR = -1;
    int lastBetweenLR = -1;

    // Record the number of all possible arrays ends with i
    for (int i = 0; i < LEN; ++i) {
        const auto& v = A[i];
        if (v > R) {
            lastR = i;
            // You cannot expect any array fulfills the requirement while ends
            // with i
            lastBetweenLR = i;
        } else if (v >= L && v <= R) {
            lastBetweenLR = i;
        }
        // The number of arrays that ends with i is expected to be the number of
        // elements between lastR and lastBetweenLR
        result += lastBetweenLR - lastR;
    }

    return result;
}

