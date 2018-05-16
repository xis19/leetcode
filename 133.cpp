#include <algorithm>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct UndirectedGraphNode {
    int label;
    std::vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (!node) return nullptr;

    std::unordered_map<int, UndirectedGraphNode*> nodes;

    // We copy all nodes first
    std::unordered_set<UndirectedGraphNode*> visited;
    std::list<UndirectedGraphNode*> bfs;
    bfs.push_back(node);
    while(!bfs.empty()) {
        auto originalNode = bfs.front();
        bfs.pop_front();

        if (visited.count(originalNode)) continue;

        auto newNode = new UndirectedGraphNode(originalNode->label);
        nodes[originalNode->label] = newNode;
        visited.insert(originalNode);

        for(auto neighbor: originalNode->neighbors) {
            bfs.push_back(neighbor);
        }
    }

    // We copy all edges then
    for(auto visitedNode: visited) {
        std::transform(
                visitedNode->neighbors.begin(), visitedNode->neighbors.end(),
                std::back_inserter(nodes[visitedNode->label]->neighbors),
                [&nodes](UndirectedGraphNode* n) -> UndirectedGraphNode* {
                    return nodes[n->label];
                }
        );
    }

    return nodes[node->label];
}
