#include <cstdlib>
#include <limits>
#include <queue>
#include <vector>

int largestSumAfterKNegations(std::vector<int>& A, int K) {
    // First flip all negative numbers, those with maximum abs number first.
    // Then flip the one with minimum absolute value with remaining Ks.
    int sum = 0;
    int min = std::numeric_limits<int>::max();

    // This is a max-heap
    std::priority_queue<int> queue;

    // All positives
    for (auto i: A) {
        if (i >= 0) {
            sum += i;
        } else {
            queue.push(-i);
        }
        min = std::min(min, std::abs(i));
    }

    // Pick up negatives and flip if possible
    while(K > 0 && !queue.empty()) {
        int v = queue.top();
        queue.pop();

        --K;
        sum += v;
    }

    // Pick up remaining values
    while(!queue.empty()) {
        int v = queue.top();
        queue.pop();
        sum -= v;
    }

    // Flip
    if (K > 0) {
        if (K % 2 == 1) {
            sum -= min * 2;
        }
    }

    return sum;
}
