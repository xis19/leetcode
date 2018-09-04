#include <vector>

int peakIndexInMountainArray(std::vector<int>& A) {
    // Basically this is looking for index for the maximum number
    int maxNum = A[0];
    size_t index = 0;
    for(size_t i = 0; i < A.size(); ++i) {
        if (A[i] > maxNum) {
            maxNum = A[i];
            index = i;
        }
    }
    return index;
}
