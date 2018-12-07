#include <algorithm>
#include <string>
#include <vector>


int minDeletionSize(const std::vector<std::string>& A) {
    if (A.size() == 0) return 0;

    const int N_COLS = A[0].size();
    const int N_ROWS = A.size();

    int D = 0;
    for(int i = 0; i < N_COLS; ++i) {
        std::string rawStr;
        rawStr.reserve(N_ROWS);
        for(const auto& s: A) {
            rawStr += s[i];
        }

        std::string sorted = rawStr;
        std::sort(sorted.begin(), sorted.end());

        D += (rawStr != sorted);
    }

    return D;
}

