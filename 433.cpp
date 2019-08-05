#include <list>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

int minMutation(const std::string& start,
                const std::string& end,
                const std::vector<std::string>& bank) {
    const int LEN = start.size();

    std::unordered_set<std::string> visited;
    visited.insert(start);

    std::list<std::pair<std::string, int>> queue;
    queue.push_back(std::make_pair(start, 0));

    while(!queue.empty()) {
        const auto elem = queue.front();
        queue.pop_front();

        const auto& s = elem.first;
        const auto& depth = elem.second;

        if (s == end) {
            return depth;
        }

        visited.insert(s);

        for (const auto& x: bank) {
            if (visited.find(x) != visited.end()) continue;
            int diffCount(0);
            for (int i = 0; i < LEN; ++i) {
                diffCount += x[i] != s[i];
            }
            if (diffCount == 1) {
                queue.push_back(std::make_pair(x, depth + 1));
            }
        }
    }

    return -1;
}
