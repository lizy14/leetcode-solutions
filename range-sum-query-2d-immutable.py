class NumMatrix(object):
    
    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        self.height = len(matrix)
        if self.height == 0:
            return
        self.width = len(matrix[0])
        if self.width == 0:
            return
        self.index = [[0 for i in range(self.width)] for j in range(self.height)]
        for y in range(self.height):
            for x in range(self.width):
                num = matrix[y][x]
                left = 0 if x == 0 else self.index[y][x-1]
                self.index[y][x] = num + left
        

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        print("sumRegion", row1, row2, col1, col2)
        if not self.index:
            return 0
        result = 0
        for row in range(row1, row2 + 1):
            result += self.sumLine(row, col1, col2)
        return result
        
    def sumLine(self, row, col1, col2):
        print("sumLine", row, col1, col2)
        num = self.index[row][col2]
        left = (0 if col1 == 0 else self.index[row][col1 - 1])
        return num - left


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
