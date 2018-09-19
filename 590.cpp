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

std::vector<int> postorder(Node* root) {
    std::vector<int> result;

    std::function<void(Node*)> traverser = [&](Node* node) -> void {
        if (node == nullptr) return;
        for(auto n: node->children) {
            traverser(n);
        }
        result.push_back(node->val);
    };

    traverser(root);
    return result;
}
