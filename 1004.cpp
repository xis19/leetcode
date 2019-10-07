#include <vector>

int longestOnes(std::vector<int>& A, int K) {
    const int LEN = A.size();

    // We use -1 to mark the 0 that is flipped, [i, j] is the current range
    // If i > j, then the range is empty.
    int i = 0;
    int j = 0;
    int maxLen(0);
    while(j < LEN) {
        auto& val = A[j];
        if (val == 0) {
            if (K == 0) {
                while (i <= j) {
                    // Find the first flipped bit
                    if (A[i] == -1) {
                        ++K;
                        ++i;
                        break;
                    }
                    ++i;
                }
            }
            // Note that K could be 0
            if (K > 0) {
                A[j] = -1;
                --K;
            }
        }
        maxLen = std::max(j - i + 1, maxLen);
        ++j;
    }

    return maxLen;
}
