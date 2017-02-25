class NumArray(object):
    
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        sum = 0
        self.sums = []
        for num in nums:
            sum += num
            self.sums.append(sum)
            

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.sums[j] - (0 if i == 0 else self.sums[i - 1])


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
