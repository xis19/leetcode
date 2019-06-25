#include <vector>

int fixedPoint(std::vector<int>& A) {
    for(size_t i = 0; i < A.size(); ++i) {
        if (static_cast<int>(i) == A[i]) {
            return i;
        }
    }
    return -1;
}
