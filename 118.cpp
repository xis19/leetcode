#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result;
    if (numRows == 0) return result;
    result.emplace_back(std::vector<int>{1});
    if (numRows == 1) return result;
    for(int i = 1; i < numRows; ++i) {
        const std::vector<int> lastRow = result.back();
        std::vector<int> r;
        r.reserve(i + 1);
        r.push_back(1);
        for(int k = 0; k < i - 1; ++k) {
            r.push_back(lastRow[k] + lastRow[k + 1]);
        }
        r.push_back(1);
        result.emplace_back(r);
    }
    return result;
}
