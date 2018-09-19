#include <functional>
#include <vector>

class Node {
    public:
        int val;
        std::vector<Node*> children;

        Node() {}

        Node(int _val, std::vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};


int maxDepth(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    int childMaxDepth = 0;
    for(auto n: root->children) {
        childMaxDepth = std::max(maxDepth(n), childMaxDepth);
    }

    return childMaxDepth + 1;
}
