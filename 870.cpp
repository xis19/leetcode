#include <algorithm>
#include <deque>
#include <vector>

std::vector<int> advantageCount(const std::vector<int>& A, const std::vector<int>& B) {
    // Find the minimum element in A that is bigger than B[i], if not exists,
    // use the minimum element.
    //
    // It would be faster if we sort A using a Red-Black tree, e.g. multiset
    std::deque<int> a(A.begin(), A.end());
    std::sort(a.begin(), a.end());

    std::vector<int> result;
    result.reserve(B.size());
    for(auto v: B) {
        if (v >= a.back()) {
            result.push_back(a.front());
            a.pop_front();
        } else {
            auto x = std::upper_bound(a.begin(), a.end(), v);
            result.push_back(*x);
            a.erase(x);
        }
    }

    return result;
}
