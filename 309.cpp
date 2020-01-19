#include <vector>

int maxProfit(const std::vector<int>& prices) {
    const int LEN = prices.size();
    std::vector<int> maxProfitSoFar{0};

    int maxProfitFound = 0;
    for (int i = 1; i < LEN; ++i) {
        // Either I do a sale today, then the profit will be
        //  profit(i) = max_j(prices(i) - prices(j) + maxProfitsSoFar(j - cooldown - 1))
        // Or I will just put a max-profit now.
        const int todayPrice = prices[i];
        int maxTodayProfit(0);
        for (int j = i - 1; j >= 0; --j) {
            const int jPrice = prices[j];
            const int todayProfit = todayPrice - jPrice;
            const int previousProfit = (j - 2) < 0 ? 0 : maxProfitSoFar[j - 2];
            maxTodayProfit = std::max(todayProfit + previousProfit, maxTodayProfit);
        }
        maxTodayProfit = std::max(maxTodayProfit, maxProfitFound);
        maxProfitSoFar.push_back(maxTodayProfit);
        maxProfitFound = std::max(maxTodayProfit, maxProfitFound);
    }

    return maxProfitFound;
}
