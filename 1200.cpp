#include <algorithm>
#include <vector>

std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
    const int LEN = arr.size();
    std::vector<std::vector<int>> result;
    if (LEN  < 2) {
        return result;
    }

    std::sort(arr.begin(), arr.end());

    int minDiff = arr[1] - arr[0];
    int prev = arr[1];
    result.push_back({arr[0], arr[1]});
    for (int i = 2; i < LEN; ++i) {
        int diff = arr[i] - prev;
        if (diff <= minDiff) {
            if (diff < minDiff) result.clear();
            minDiff = diff;
            result.push_back({prev, arr[i]});
        }
        prev = arr[i];
    }

    return result;
}
