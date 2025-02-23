# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def constructFromPrePost(self, preorder, postorder):
        postIdx = {}
        for idx, order in enumerate(postorder):
            postIdx[order] = idx
        return self.solve(preorder, postorder, postIdx, 0, len(preorder) - 1, 0, len(postorder) - 1, len(preorder))

    def solve(self, preorder, postorder, postIdx, preStart, preEnd, postStart, postEnd, sz):
        if preStart > preEnd:
            return None
        node = TreeNode(preorder[preStart])
        if preStart >= preEnd:
            return node
        length = postIdx[preorder[preStart + 1]] - postStart
        node.left = self.solve(preorder, postorder, postIdx, preStart + 1, preStart + 1 + length, postStart, postStart + length, sz)
        node.right = self.solve(preorder, postorder, postIdx, preStart + length + 2, preEnd, postStart + length + 1, postEnd - 1, sz)
        return node

        