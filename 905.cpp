#include <vector>

std::vector<int> sortArrayByParity(std::vector<int>& A) {
    const int LEN = A.size();
    if (LEN < 2) return A;

    int lastNotEven(0);
    for(int lastEven = 0; lastEven < LEN; ++lastEven) {
        if ((A[lastEven] & 1) == 0) {
            std::swap(A[lastNotEven++], A[lastEven]);
        }
    }

    return A;
}

