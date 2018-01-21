#include <functional>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


TreeNode* buildTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
    const int NELEMENTS = preorder.size();

    std::function<TreeNode*(int, int, int, int)> construct =
        [&construct, &preorder, &inorder](int pL, int pR, int iL, int iR) -> TreeNode* {

        if (pL == pR) {
            return nullptr;
        }

        int value = preorder[pL];
        TreeNode* node = new TreeNode(value);

        int iI = iL;
        for(; iI < iR; ++iI) {
            if (inorder[iI] == value) {
                // Note: All values are unique!
                int numLeftBranch = iI - iL;
                node->left = construct(pL + 1, pL + 1 + numLeftBranch, iL, iI);
                int numRightBranch = iR - iI - 1;
                node->right = construct(pL + numLeftBranch + 1, pL + numLeftBranch + numRightBranch + 1, iI + 1, iR);
                break;
            }
        }

        return node;
    };

    return construct(0, NELEMENTS, 0, NELEMENTS);
}
