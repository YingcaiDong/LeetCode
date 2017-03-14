'''
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
''''

class Solution(object):
	def productExceptSelf(self, nums):
		"""
		:type nums: List[int]
		:rtype: List[int]
		"""
		p=1
		result=[]
		for i in nums:
			result.append(p)
			p *= i
		p=1
		for i in range(len(nums)-1, -1, -1):
			result[i] *= p
			p *= nums[i]
		return result
