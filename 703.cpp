#include <limits>
#include <queue>
#include <vector>

class KthLargest {
    const size_t K;
    std::priority_queue<int, std::vector<int>, std::greater<int>> kValues;
public:
    KthLargest(int k, const std::vector<int>& nums): K(k), kValues(k, std::numeric_limits<int>::min()) {
        for(auto v: nums) {
            add(v);
        }
    }

    int add(int val) {
        // Use a min-heap
        if (kValues.size() < K) {
            kValues.push(val);
            return kValues.top();
        } else {
            if (val > kValues.top()) {
                kValues.push(val);
                kValues.pop();
            }
            return kValues.top();
        }
    }
};
