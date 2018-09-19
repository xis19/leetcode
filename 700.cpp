struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return nullptr;
    } else if (root->val == val) {
        return root;
    } else if (val > root->val) {
        return searchBST(root->right, val);
    } else {
        return searchBST(root->left, val);
    }
}