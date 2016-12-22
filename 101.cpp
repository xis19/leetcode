#include <functional>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isSymmetric(TreeNode* root) {
    std::function<bool(TreeNode*, TreeNode*)> recursive = [&](TreeNode* lBranch, TreeNode* rBranch) -> bool {
        int numNullptrs = (lBranch == nullptr) + (rBranch == nullptr);
        switch(numNullptrs) {
            case 2:
                return true;
            case 1:
                return false;
            default:
                return lBranch->val == rBranch->val && recursive(lBranch->left, rBranch->right) && recursive(lBranch->right, rBranch->left);
        }
    };

    std::function<bool(TreeNode*, TreeNode*)> iterative = [&](TreeNode* lBranch, TreeNode* rBranch) -> bool {
        std::stack<TreeNode*> lHistory, rHistory;
        lHistory.push(lBranch);
        rHistory.push(rBranch);
        while(!lHistory.empty()) {
            auto lNode = lHistory.top();
            auto rNode = rHistory.top();
            int numNullptrs = (lNode == nullptr) + (rNode == nullptr);
            switch(numNullptrs) {
                case 1:
                    return false;
                case 2:
                    lHistory.pop();
                    rHistory.pop();
                    break;
                case 0:
                    if (lNode->val != rNode->val) {
                        return false;
                    }
                    lHistory.pop();
                    rHistory.pop();
                    lHistory.push(lNode->left);
                    lHistory.push(lNode->right);
                    rHistory.push(rNode->right);
                    rHistory.push(rNode->left);
                    break;
            }
        }
        return true;
    };

    return (root == nullptr) || recursive(root->left, root->right);
}
