class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


def binaryTreePaths(root):
    if root is None:
        return []

    result = []
    path = []
    def traverse(node):
        path.append(node.val)
        if node.left is None and node.right is None:
            result.append('->'.join(str(v) for v in path))
        else:
            if node.left:
                traverse(node.left)
            if node.right:
                traverse(node.right)
        path.pop()

    traverse(root)
    return result
