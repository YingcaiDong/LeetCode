class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict = {}
        for i in set(s):
            dict[i] = 0
        for i in s:
            dict[i] += 1
        for i, j in enumerate(s):
            if dict[j] == 1:
                return i
        return -1
