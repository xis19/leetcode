#include <vector>

double findMaxAverage(std::vector<int>& nums, int k) {
    double sum(0);
    auto iter = nums.begin();
    for(int i = 0; i < k; ++i, ++iter) {
        sum += static_cast<double>(*iter) / k;
    }
    auto backIter = nums.begin();
    double max = sum;
    while(iter != nums.end()) {
        sum -= static_cast<double>(*backIter) / k;
        sum += static_cast<double>(*iter) / k;
        max = std::max(max, sum);
        ++iter, ++backIter;
    }
    return max;
}
