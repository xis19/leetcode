#include <algorithm>
#include <limits>
#include <vector>

int partitionDisjoint(const std::vector<int>& A) {
    const int LEN = A.size();

    std::vector<int> minA;
    minA.reserve(LEN);

    {
        int min = std::numeric_limits<int>::max();
        for(auto i = A.rbegin(); i != A.rend(); ++i) {
            if (*i < min) {
                min = *i;
            }
            minA.push_back(min);
        }
    }

    std::reverse(minA.begin(), minA.end());

    {
        int max = std::numeric_limits<int>::min();
        for (int i = 0; i < LEN - 1; ++i) {
            if (A[i] > max) {
                max = A[i];
            }
            if (max <= minA[i + 1]) return i + 1;
        }
    }

    return -1;
}
