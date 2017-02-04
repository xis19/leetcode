#include <algorithm>
#include <limits>
#include <vector>


int numberOfArithmeticSlices(const std::vector<int>& A) {
    int lastDelta = std::numeric_limits<int>::max();
    int currentLongestSliceLength(2);
    int totalSlices(0);

    auto numSubSlices = [](int sliceLength) {
        // For a slice, e.g. 1, 2, 3, 4, 5, the possible sub slices rae
        //
        //  1, 2, 3; 2, 3, 4; 3, 4, 5       -- (n - 3 + 1) slices
        //  1, 2, 3, 4; 2, 3, 4, 5          -- (n - 4 + 1) slices
        //  1, 2, 3, 4, 5                   -- (n - n + 1) slices
        //
        // So the number of subslices are sum(n - 3 + 1, ... n - n + 1) total
        // n - 2 items, that is,
        //  sum(n + 1, n + 1, ...) - sum(3, ... n),
        // or
        //  (n + 1) * (n - 2) - (n + 3) * (n - 2) / 2
        //
        // NOTE: extract (n - 2) out is unwise
        if (sliceLength <= 2) {
            return 0;
        }
        return (sliceLength + 1) * (sliceLength - 2) - (sliceLength + 3) * (sliceLength - 2) / 2;
    };

    for(size_t i = 1; i < A.size(); ++i) {
        int delta = A[i] - A[i - 1];
        if (delta == lastDelta) {
            currentLongestSliceLength++;
        } else {
            totalSlices += numSubSlices(currentLongestSliceLength);
            currentLongestSliceLength = 2;  // two elements at first
        }
        lastDelta = delta;
    }

    if (currentLongestSliceLength > 2) {
        totalSlices += numSubSlices(currentLongestSliceLength);
    }

    return totalSlices;
}

