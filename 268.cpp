#include <vector>

int missingNumber(std::vector<int>& nums) {
    const int N = nums.size();
    const int SHIFT = N + 1;
    int NMissing = true;

    for(int i = 0; i < N; ++i) {
        int val = nums[i] > N ? nums[i] - SHIFT : nums[i];
        if (val == N) {
            NMissing = false;
        } else {
            nums[val] += SHIFT;
        }
    }

    if (NMissing) return N;
    for(int i = 0; i < N; ++i) {
        if (nums[i] <= N) return i;
    }
}
