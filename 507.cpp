#include <numeric>
#include <vector>

bool checkPerfectNumber(int num) {
    if (num == 1) return false;

    std::vector<int> factors{1};
    int ending = num;
    for(int i = 2; i < ending; ++i) {
        if (num % i == 0) {
            ending = num / i;
            factors.push_back(i);
            factors.push_back(ending);
        }
    }

    return std::accumulate(factors.begin(), factors.end(), 0) == num;
}
