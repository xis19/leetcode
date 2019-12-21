#include <unordered_map>
#include <vector>

int findMaxLength(const std::vector<int>& nums) {
    // Use a counter = 0
    // If we meet a 1, then increase it
    // If we meet a 0, then decrease it
    // Any two indexes, i, j, if the counter is the same, then it implies
    // between i and j, the number of 1s and 0s are the same.
    const int LEN = nums.size();
    int counter = 0;
    // We map the counter with the minimal index the counter has the value
    std::unordered_map<int, int> counterIndexMap{{0, -1}};
    int result = 0;
    for (int i = 0; i < LEN; ++i) {
        if (nums[i] == 1) ++counter; else --counter;
        if (counterIndexMap.find(counter) == counterIndexMap.end()) {
            counterIndexMap[counter] = i;
        }
        result = std::max(result,i - counterIndexMap[counter]);
    }
    return result;
}
