#include <functional>
#include <string>
#include <vector>
#include <unordered_set>

int totalNQueens(int n) {
    int result(0);

    std::vector<int> nQ(n);
    std::function<void(int)> recursive = [&](int row) -> void {
        if (row == n) {
            ++result;
        }

        // Find all available positions for this row
        std::unordered_set<int> unavailables;
        for(int i = 0; i < row; ++i) {
            unavailables.insert(nQ[i]);
            unavailables.insert(nQ[i] + row - i);
            unavailables.insert(nQ[i] - row + i);
        }

        for(int i = 0; i < n; ++i) {
            if (unavailables.find(i) != unavailables.end()) {
                continue;
            }
            nQ[row] = i;
            recursive(row + 1);
        }
    };

    recursive(0);

    return result;
}
