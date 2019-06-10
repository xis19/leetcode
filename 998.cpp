 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };


TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val > root->val) {
        TreeNode* node = new TreeNode(val);
        node->left = root;
        return node;
    }

    root->right = insertIntoMaxTree(root->right, val);
    return root;
}
