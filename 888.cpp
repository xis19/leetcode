#include <cmath>
#include <numeric>
#include <unordered_set>
#include <vector>

std::vector<int> fairCandySwap(const std::vector<int>& A, const std::vector<int>& B) {
    int aSum = std::accumulate(A.begin(), A.end(), 0);
    int bSum = std::accumulate(B.begin(), B.end(), 0);

    int diff = (bSum - aSum) / 2;

    std::unordered_set<int> bSet;
    for(auto elem: B) bSet.insert(elem);

    for(auto aElem: A) {
        if (bSet.find(aElem + diff) != bSet.end()) {
            return std::vector<int>{aElem, aElem + diff};
        }
    }
    throw std::exception();
}
