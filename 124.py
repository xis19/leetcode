class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def maxPathSum(root: TreeNode) -> int:
    result = [-999999]

    def traverse(node: TreeNode):
        left = traverse(node.left) if node.left else 0
        right = traverse(node.right) if node.right else 0

        result[0] = max(node.val, left + node.val + right,
                        left + node.val, right + node.val,
                        result[0])

        return max(left + node.val, right + node.val, node.val)

    traverse(root)
    return result[0]
