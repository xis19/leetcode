#include <functional>
#include <string>
#include <vector>
#include <unordered_set>

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> result;

    std::vector<int> nQ(n);
    auto generateNQ = [&result, &nQ, n]() -> void {
        std::vector<std::string> r;
        r.reserve(n);

        for(auto c: nQ) {
            std::string t;
            t.resize(n);
            std::fill(std::begin(t), std::end(t), '.');
            t[c] = 'Q';
            r.emplace_back(t);
        }

        result.emplace_back(r);
    };

    std::function<void(int)> recursive = [&](int row) -> void {
        if (row == n) {
            generateNQ();
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
