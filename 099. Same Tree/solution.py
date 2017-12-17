#!python3


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if p and q:
            return p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
        return p is q


if __name__ == "__main__":
    example1 = TreeNode(1)
    example1.left = TreeNode(2)
    example1.right = TreeNode(3)
    assert(Solution().isSameTree(example1, example1) is True)

    example2l = TreeNode(1)
    example2l.left = TreeNode(2)
    example2r = TreeNode(1)
    example2r.right = TreeNode(2)
    assert(Solution().isSameTree(example2l, example2r) is False)

    example3l = TreeNode(1)
    example3l.left = TreeNode(2)
    example3l.right = TreeNode(1)
    example3r = TreeNode(1)
    example3r.left = TreeNode(1)
    example3r.right = TreeNode(2)
    assert(Solution().isSameTree(example3l, example3r) is False)
