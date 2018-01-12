#include <algorithm>
#include <queue>
#include <vector>

int findKthLargest(const std::vector<int>& nums, size_t k) {
    // We keep maintaining a minimal heap, with size k
    std::priority_queue<int, std::vector<int>, std::greater<int>> heap;

    for(auto i: nums) {
        heap.push(i);
        if (heap.size() > k) heap.pop();
    }

    return heap.top();
}
