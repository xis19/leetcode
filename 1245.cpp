#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int treeDiameter(const std::vector<std::vector<int>>& edges) {
    // For ever node, it could be either
    //  * The root of the tree with the largest diameter
    //  * Part of the largest diameter path
    // As a tree, any node could be root, we pick up 0 as the root
    std::unordered_map<int, std::unordered_set<int>> edge;
    for(auto e: edges) {
        edge[e[0]].insert(e[1]);
        edge[e[1]].insert(e[0]);
    }

    int pathWithMaximumNodes = -1;
    std::function<int(int, int)> traverse = [&traverse, &pathWithMaximumNodes, &edge] (int node, int parent) -> int {
        int longestTwo[2] = {0, 0};
        for (auto e: edge[node]) {
            if (e == parent) continue;
            const int length = traverse(e, node);
            if (length > longestTwo[1]) {
                longestTwo[0] = longestTwo[1];
                longestTwo[1] = length;
            } else if (length > longestTwo[0]) {
                longestTwo[0] = length;
            }
        }
        pathWithMaximumNodes = std::max(pathWithMaximumNodes, longestTwo[0] + longestTwo[1] + 1);
        return longestTwo[1] + 1;
    };

    traverse(0, 0);
    return pathWithMaximumNodes - 1;
}
