#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>

std::string minimizeError(const std::vector<std::string>& prices, int target) {
    // Although a first sight will be DP, noticing that doing a round will cause
    // the sum fluctuate by 1... we could do a greedy approach

    // Split the price integer/decimal part
    std::vector<int> sPrices;
    int sumFloor = 0;
    for (const auto& p: prices) {
        int priceInt = std::stoi(p);
        int priceDec = std::stoi(p.substr(p.size() - 3));
        // for .000, you cannot ceil
        if (priceDec != 0) sPrices.push_back(priceDec);
        sumFloor += priceInt;
    }

    if (sumFloor > target) return "-1";

    const int CEILABLE_LEN = sPrices.size();
    if (target - sumFloor > CEILABLE_LEN) return "-1";

    // Descending order sort
    std::sort(sPrices.begin(), sPrices.end(),
        [](const int i1, const int i2) {
            return i1 > i2;
        });

    int fluct(0);
    for (int i = 0; i < CEILABLE_LEN; ++i) {
        if (i < target - sumFloor) {
            fluct += 1000 - sPrices[i];
        } else {
            fluct += sPrices[i];
        }
    }

    auto flt = std::to_string(fluct % 1000);
    while(flt.size() < 3) flt = '0' + flt;

    return std::to_string(fluct / 1000) + '.' + flt;
}
