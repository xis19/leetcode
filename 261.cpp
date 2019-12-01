#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

bool validTree(int n, const std::vector<std::vector<int>>& edges) {
    std::unordered_map<int, std::unordered_set<int>> edge;
    for (const auto& e: edges) {
        edge[e[0]].insert(e[1]);
        edge[e[1]].insert(e[0]);
    }

    // In a tree, any node can be the root, so we will just pick up the 0th
    // element.
    // Check if there is a cycle -- we need to record the "parent" so we do not
    // revisit the "parent" -- as the tree edges are undirected.
    std::unordered_set<int> visited;
    // node -- parent
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, 0));
    visited.insert(0);
    while (!q.empty()) {
        const auto _ = q.front();
        const auto vertex = _.first;
        const auto parent = _.second;

        q.pop();

        for (const auto linkedVertex: edge[vertex]) {
            if (linkedVertex == parent) continue;
            if (visited.find(linkedVertex) != visited.end()) return false;
            visited.insert(linkedVertex);
            q.push(std::make_pair(linkedVertex, vertex));
        }
    }

    return visited.size() == static_cast<size_t>(n);
}
