int removeDuplicates(int* nums, int numsSize) {
    if (!numsSize)
        return 0;

    // sIndex is the slow index, any values before sIndex is de-duped
    // fIndex is the fast index
    int sIndex = 0, fIndex = 1;
    for(;fIndex < numsSize; ++fIndex) {
        if (nums[fIndex] != nums[sIndex]) {
            ++sIndex;
            nums[sIndex] = nums[fIndex];
        }
    }
    return sIndex + 1;
}
