#include <map>
#include <unordered_map>
#include <vector>

int minimumCost(int N, const std::vector<std::vector<int>>& connections) {
    std::multimap<int, std::pair<int, int>> conns;
    for (auto& connection: connections) {
        conns.insert(std::make_pair(
            connection[2], std::make_pair(connection[1], connection[0]))
        );
    }

    std::unordered_map<int, int> unionFind;
    for (int i = 1; i <= N; ++i) { unionFind[i] = i; }
    auto findRoot = [&unionFind](int n) -> int {
        while (unionFind[n] != n) {
            n = unionFind[n];
        }
        return n;
    };
    auto join = [&unionFind, &findRoot](int u, int v) {
        auto ur = findRoot(u);
        auto vr = findRoot(v);
        unionFind[vr] = ur;
    };

    int score = 0;
    for (auto& conn: conns) {
        auto len = conn.first;
        auto node1 = conn.second.first;
        auto node2 = conn.second.second;

        if (findRoot(node1) == findRoot(node2)) {
            continue;
        }

        join(node1, node2);
        score += len;
    }

    auto root = findRoot(1);
    for (int i = 2; i <= N; ++i) {
        if (findRoot(i) != root) return -1;
    }

    return score;
}
