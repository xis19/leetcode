struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

TreeNode* invertTree(TreeNode* root) {
    if (root) {
        std::swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
    }
    return root;
}
