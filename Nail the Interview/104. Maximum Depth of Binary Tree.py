# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        flag = True
        cnt = 0
        if root:
            level = [root]
        else:
            return 0
        while flag:
            temp_level=[]
            for i in level:
                if i.left:
                    temp_level.append(i.left)
                if i.right:
                    temp_level.append(i.right)
            cnt+=1
            if len(temp_level) == 0:
                flag = False
            else:
                level = temp_level
        return cnt
