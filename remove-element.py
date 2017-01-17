class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        result = list(filter(lambda x: x != val, nums))
        for i, k in enumerate(result):
            nums[i] = k
        return len(result)
