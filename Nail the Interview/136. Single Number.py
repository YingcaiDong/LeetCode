class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.sort()
        if len(nums) < 2:
            return nums[0]
        else:
            for i in range(0, len(nums)-1, 2):
                if nums[i] != nums[i+1]:
                    return nums[i]
            return nums[len(nums)-1]
