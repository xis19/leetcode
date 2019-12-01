#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

std::vector<int> shortestAlternatingPaths(
            int n,
            const std::vector<std::vector<int>>& red_edges,
            const std::vector<std::vector<int>>& blue_edges) {

    std::unordered_map<char, std::unordered_map<int, std::unordered_set<int>>> edges;
    for (const auto& e: red_edges) edges['r'][e[0]].insert(e[1]);
    for (const auto& e: blue_edges) edges['b'][e[0]].insert(e[1]);

    std::vector<int> result(n, std::numeric_limits<int>::max());
    auto traverse = [&edges, &result](char zeroColor) {
        std::queue<std::tuple<int, int, char>> q;
        q.push(std::make_tuple(0, 0, zeroColor));
        std::unordered_map<char, std::unordered_set<int>> visited;
        visited[zeroColor].insert(0);

        while (!q.empty()) {
            auto _ = q.front();
            q.pop();

            const int vertex = std::get<0>(_);
            const int depth = std::get<1>(_);
            const char color = std::get<2>(_);
            const char nextColor = color == 'r' ? 'b' : 'r';

            if (result[vertex] > depth) result[vertex] = depth;

            for (auto connectedVertex: edges[nextColor][vertex]) {
                if (visited[nextColor].find(connectedVertex) == visited[nextColor].end()) {
                    visited[nextColor].insert(connectedVertex);
                    q.push(std::make_tuple(connectedVertex, depth + 1, nextColor));
                }
            }
        }
    };

    traverse('r');
    traverse('b');

    std::transform(result.begin(), result.end(), result.begin(), [](int v) {
                if (v == std::numeric_limits<int>::max()) {
                    return -1;
                }
                return v;
            });

    return result;
}
