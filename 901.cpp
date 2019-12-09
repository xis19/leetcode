#include <stack>
#include <utility>

class StockSpanner {
    int index = 0;
    std::stack<std::pair<int, int>> prices;
public:
    StockSpanner() {}

    int next(int price) {
        while (!prices.empty() && prices.top().first <= price) {
            prices.pop();
        }

        auto result = 0;
        if (prices.empty()) {
            result = index;
        } else {
            result = index - prices.top().second - 1;
        }

        prices.push(std::make_pair(price, index++));

        return result + 1;
    }
};

