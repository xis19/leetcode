#include <vector>

void moveZeroes(std::vector<int>& nums) {
    const int LEN = nums.size();
    int nonzero, zero = 0;
    while(true) {
        while(zero < LEN && nums[zero] != 0) ++zero;
        nonzero = zero + 1;
        while(nonzero < LEN && nums[nonzero] == 0) ++nonzero;

        if (zero < LEN && nonzero < LEN)
            std::swap(nums[zero], nums[nonzero]);
        else
            break;
    }
}

// This does not preserve the order of the numbers
void moveZeroesBad(std::vector<int>& nums) {
    const int LEN = nums.size();
    int nonzero = 0, zero = LEN - 1;
    while(nonzero < zero) {
        while(nonzero < zero && nums[nonzero] != 0) ++nonzero;
        while(zero > nonzero && nums[zero] == 0) --zero;
        std::swap(nums[nonzero], nums[zero]);
    }
}
