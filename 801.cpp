#include <limits>
#include <vector>


int minSwap(const std::vector<int>& A, const std::vector<int>& B) {
    // Typical DP problem
    const int LEN = A.size();
    const int MAXINT = std::numeric_limits<int>::max();
    std::vector<int> f_unswapped(LEN, 0);
    std::vector<int> f_swapped(LEN, 0);
    f_swapped[0] = 1;

    for (int i = 1; i < LEN; ++i) {
        int c1(MAXINT), c2(MAXINT), c3(MAXINT), c4(MAXINT);
        if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
            c1 = f_unswapped[i - 1];
            c3 = f_swapped[i - 1];
        }
        if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
            c2 = f_swapped[i - 1];
            c4 = f_unswapped[i - 1];
        }
        f_unswapped[i] = std::min(c1, c2);
        f_swapped[i] = std::min(c3, c4);
        if (f_swapped[i] != MAXINT) ++f_swapped[i];
    }

    return std::min(f_swapped.back(), f_unswapped.back());
}
