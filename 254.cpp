#include <functional>
#include <unordered_map>
#include <vector>

std::vector<std::vector<int>> getFactors(int n) {
    // The most straightforward approach is to extract all factors and then
    // combine them in order. However, it is complicated to do so.
    std::vector<std::vector<int>> result;

    std::function<void(int, std::vector<int>&&)> factorize = [&result, &factorize](int num, std::vector<int>&& factors) {
        // Only consider the factors less than sqrt(num), this avoids we have
        // duplicate values, e.g. for 8
        //
        //  2 * 4
        //  4 * 2
        //
        // Also, in each iterator, we always start with the number larger
        // than the last one, to avoid the duplicates.
        const int start = factors.size() == 0 ? 2 : factors.back();
        for(int i = start; i * i <= num; ++i) {
            if (num % i == 0) {
                result.push_back(factors);
                result.back().push_back(i);
                result.back().push_back(num / i);

                factors.push_back(i);
                factorize(num / i, std::move(factors));
                factors.pop_back();
            }
        }
    };

    factorize(n, std::vector<int>());

    return result;
}
