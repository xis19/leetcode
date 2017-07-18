#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<double> averageOfLevels(TreeNode* root) {
    std::vector<double> result;
    if (root == nullptr) return result;

    std::vector<TreeNode*> curr;
    curr.push_back(root);
    std::vector<TreeNode*> childs;
    while(!curr.empty()) {
        double sum(0);
        int count(0);
        childs.clear();
        for(auto i: curr) {
            sum += i->val;
            if (i->left) childs.push_back(i->left);
            if (i->right) childs.push_back(i->right);
            ++count;
        }
        result.push_back(sum / count);
        childs.swap(curr);
    }
    return result;
}
