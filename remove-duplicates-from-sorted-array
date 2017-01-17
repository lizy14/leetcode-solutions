from itertools import groupby

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = [k for k, g in groupby(nums)]
        for i, k in enumerate(result):
            nums[i] = k
        return len(result)
