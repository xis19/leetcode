#include <algorithm>
#include <deque>
#include <unordered_map>
#include <vector>

bool isNStraightHand(const std::vector<int>& hand, int W) {
    std::deque<std::pair<int, int>> cardCount;

    {
        std::unordered_map<int, decltype(cardCount.begin())> map;
        for (auto c: hand) {
            auto f = map.find(c);
            if (f == map.end()) {
                cardCount.emplace_back(std::make_pair(c, 0));
                map[c] = cardCount.end() - 1;
            }
            ++map[c]->second;
        }
    }

    std::sort(cardCount.begin(), cardCount.end(),
            [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
                return a.first < b.first;
            }
        );

    while(!cardCount.empty()) {
        auto first = cardCount.front();
        cardCount.pop_front();

        if (static_cast<int>(cardCount.size()) < W - 1) return false;
        for (int i = 0; i < W - 1; ++i) {
            auto& c = cardCount[i];
            if (c.second < first.second || c.first != first.first + i + 1) {
                return false;
            }
            c.second -= first.second;
        }
        while(!cardCount.empty() && cardCount.front().second == 0)
            cardCount.pop_front();
    }

    return true;
}
