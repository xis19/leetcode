#include <functional>
#include <unordered_map>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool checkEqualTree(TreeNode* root) {
    // Noticing that node value can be negative... When the sum of the tree is
    // zero, e.g.
    //    0
    //  /   \
    //  1   -1
    // would be nasty. Here we record *every* node, we could also traverse the
    // tree twice, one for sum and the other for half value.
    std::unordered_map<int, std::unordered_set<TreeNode*>> sumFromBottomToUp;
    std::function<int(TreeNode*)> sumUp = [&sumFromBottomToUp, &sumUp](TreeNode* n) {
        if (n == nullptr) return 0;
        int sum = sumUp(n->left) + sumUp(n->right) + n->val;
        sumFromBottomToUp[sum].insert(n);
        return sum;
    };
    int sumAll = sumUp(root);
    if (sumAll % 2 == 0) {
        int half = sumAll / 2;
        if (sumFromBottomToUp.find(half) != sumFromBottomToUp.end()) {
            if (sumFromBottomToUp[half].find(root) != sumFromBottomToUp[half].end()) {
                return sumFromBottomToUp[half].size() > 1;
            }
            return true;
        }
    }
    return false;
}
