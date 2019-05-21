class ArrayReader { public: int get(int) const ; };

int search(const ArrayReader& reader, int target) {
    // First, explore the boundary of search
    int start = 0;
    int end = 1;

    {
        int value = reader.get(end);
        while(value <= target) {
            start = end;
            end *= 2;
            value = reader.get(end);
        }
    }

    // binary search is easier when using closed regions
    --end;
    int mid;
    while(start <= end) {
        mid = start + (end - start) / 2;
        int value = reader.get(mid);
        if (value < target) {
            start = mid + 1;
        } else if (value > target) {
            end = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}
