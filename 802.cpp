#include <algorithm>
#include <functional>
#include <stdexcept>
#include <unordered_set>
#include <vector>

std::vector<int> eventualSafeNodes(const std::vector<std::vector<int>>& graph) {
    std::unordered_set<int> result;
    std::unordered_set<int> visited;
    std::function<void(int)> dfs = [&graph, &visited, &dfs, &result](int n) -> void {
        if (graph[n].empty() || result.find(n) != result.end()) {
            // Terminal
            result.insert(n);
            return;
        }

        visited.insert(n);
        for (auto& t: graph[n]) {
            if (visited.find(t) != visited.end()) {
                throw std::runtime_error("Cyclic found");
            }
            dfs(t);
        }
        result.insert(n);
        visited.erase(n);
    };

    const int N = graph.size();
    for (int i = 0; i < N; ++i) {
        try {
            dfs(i);
        } catch (std::runtime_error& ex) {
        }
    }

    auto ret = std::vector<int>{result.begin(), result.end()};
    std::sort(ret.begin(), ret.end());
    return ret;
}
