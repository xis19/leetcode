#include <numeric>
#include <vector>

bool canThreePartsEqualSum(const std::vector<int>& A) {
    int sum = std::accumulate(A.begin(), A.end(), 0);
    if (sum % 3 != 0) return false;

    auto iter = A.begin();
    int s1 = 0;
    while(s1 != sum / 3 && iter != A.end()) {
        s1 += *iter;
        ++iter;
    }

    if (iter == A.end()) {
        return false;
    }

    int s2 = 0;
    while(s2 != sum / 3 && iter != A.end()) {
        s2 += *iter;
        ++iter;
    }
    if (iter == A.end()) {
        return false;
    }

    return true;
}
