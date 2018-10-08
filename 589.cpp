#include <algorithm>
#include <functional>
#include <deque>
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


std::vector<int> preorder(Node* root) {
    std::vector<int> result;
    if (!root) return result;

    std::deque<Node*> q;
    q.push_back(root);

    while(!q.empty()) {
        auto front = q.front();
        q.pop_front();
        result.push_back(front->val);
        for(auto iter = front->children.rbegin(); iter != front->children.rend(); ++iter) {
            q.push_front(*iter);
        }
    }

    return result;
}
