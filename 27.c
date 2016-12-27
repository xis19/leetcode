int removeElement(int* nums, int numsSize, int val) {
    if (!nums) return 0;

    int* start = nums;
    int* end = nums + numsSize - 1;
    int newSize = 0;
    int tmp;
    // Must consider start <= end, since the int at end may also be an element
    // not equal to val.
    while(start <= end) {
        if (*start == val) {
            tmp = *start;
            *start = *end;
            *end = tmp;
            --end;
        } else {
            ++start;
            ++newSize;
        }
    }

    return newSize;
}
