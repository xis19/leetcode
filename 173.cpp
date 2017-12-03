struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class BSTIterator {
    TreeNode* me;
    BSTIterator* lBranch;
    BSTIterator* rBranch;
    // 0 for left, 1 for current, 2 for right
    int status;
public:
    BSTIterator(TreeNode* root) : me(root), lBranch(nullptr), rBranch(nullptr), status(1) {
        if (!root)
            return;

        if (root->left) {
            lBranch = new BSTIterator(root->left);
            status = 0;
        }
        if (root->right)
            rBranch = new BSTIterator(root->right);
    }

    bool hasNext() {
        switch(status) {
            case 0:
                return true;
            case 1:
                return me != nullptr;
            case 2:
                if (rBranch)
                    return rBranch->hasNext();
                else
                    return false;
            default:
                return false;
        }
    }

    int next() {
        if (status == 0) {
            if (lBranch->hasNext()) {
                return lBranch->next();
            } else {
                // We visited all lBranch, we should return the current one
                status = 1;
            }
        }

        if (status == 1) {
            status = 2;
            return me->val;
        }

        if (rBranch) {
            return rBranch->next();
        }

        return -1;
    }

    ~BSTIterator() {
        delete lBranch;
        delete rBranch;
    }
};
