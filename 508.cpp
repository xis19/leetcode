#include <functional>
#include <map>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> findFrequentTreeSum(TreeNode* root) {
    if (!root) return std::vector<int>();

    std::map<int, int> counter;
    std::function<int(TreeNode*)> traverser = [&](TreeNode* visitor) -> int {
        int value = visitor->val;
        if (visitor->left) value += traverser(visitor->left);
        if (visitor->right) value += traverser(visitor->right);
        ++counter[value];
        return value;
    };
    traverser(root);

    std::vector<int> result;
    int max_occur = counter.begin()->second;
    for(auto& item: counter) {
        if (item.second > max_occur) {
            result.clear();
            result.push_back(item.first);
            max_occur = item.second;
        } else if (item.second == max_occur) {
            result.push_back(item.first);
        }
    }

    return result;
}
