#include <array>
#include <string>
#include <tuple>
#include <vector>

bool buddyStrings(const std::string& A, const std::string& B) {
    if (A.size() != B.size()) return false;

    const int LEN = A.size();
    // Must have at least one switch
    if (LEN < 2) return false;

    if (A == B) {
        // If the two strings are the same, we check if there are two same
        // characters we can swap
        std::array<int, 26> charCount;
        std::fill(charCount.begin(), charCount.end(), 0);

        for(auto ch: A) {
            ++charCount[ch - 'a'];
        }
        for(auto v: charCount) {
            if (v > 1) return true;
        }

        return false;
    } else {
        // Check for 2 differences
        int iDiffs(0);
        int diffPos[2];
        for(int i = 0; i < LEN; ++i) {
            if (A[i] == B[i]) continue;

            if (iDiffs >= 2) return false;
            diffPos[iDiffs++] = i;
        }
        if (iDiffs == 2 && A[diffPos[0]] == B[diffPos[1]] && A[diffPos[1]] == B[diffPos[0]]) {
            return true;
        }
        return false;
    }
}
