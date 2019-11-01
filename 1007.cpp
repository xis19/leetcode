#include <algorithm>
#include <vector>

int minDominoRotations(const std::vector<int>& A, const std::vector<int>& B) {
    // Since there are only two possibilities to make one row (A, B) equal --
    // A[0] and B[0], we will try to rotate A at A[0] or B[0], then rotate B at
    // A[0] or B[0], check the result.
    const int LEN = A.size();

    auto tryRotate = [&LEN](const std::vector<int>& v1, const std::vector<int>& v2, int refVal) -> int {
        // Try to rotate v2 to v1 to let v1 has value refVal. If not possible,
        // return -1; otherwise return number of rotates
        int numRotates = 0;
        for (int i = 0; i < LEN; ++i) {
            if (v1[i] == refVal) continue;
            if (v2[i] == refVal)
                ++numRotates;
            else
                return -1;
        }
        return numRotates;
    };

    std::vector<int> result{
        tryRotate(A, B, A[0]),
        tryRotate(A, B, B[0]),
        tryRotate(B, A, A[0]),
        tryRotate(B, A, B[0])
    };

    int min = *std::max_element(result.begin(), result.end());
    // no possible?
    if (min == -1) return -1;
    for (auto r: result) {
        if (r == -1) continue;
        min = std::min(r, min);
    }
    return min;
}
