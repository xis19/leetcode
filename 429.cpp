#include <queue>
#include <vector>

class Node {
public:
    int val = 0;
    std::vector<Node*> children;

    Node() {}

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

std::vector<std::vector<int>> levelOrder(Node* root) {
    std::vector<std::vector<int>> result;
    if (!root) return result;

    std::queue<std::pair<Node*, int>> visitQueue;
    visitQueue.push(std::make_pair(root, 0));

    while(!visitQueue.empty()) {
        auto object = visitQueue.front();
        visitQueue.pop();

        if (object.second + 1 > static_cast<int>(result.size())) {
            result.emplace_back(std::vector<int>());
        }

        result[object.second].push_back(object.first->val);

        for(auto node: object.first->children) {
            visitQueue.push(std::make_pair(node, object.second + 1));
        }
    }

    return result;
}
