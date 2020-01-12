class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

def sumEvenGrandparent(root: TreeNode) -> int:
    s = [0]
    stack = [None, None]
    def traverse(node: TreeNode):
        if not node:
            return

        stack.append(node.val)
        if stack[-3] and stack[-3] % 2 == 0:
            s[0] += node.val
        traverse(node.left)
        traverse(node.right)
        stack.pop()

    traverse(root)
    return s[0]
