class InvalidSoduku(BaseException):
    pass

class Solution(object):

    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        rg = range(9)
        srg = range(3)

        def one_to_nine(arr):
            cells = [i for i in arr if i != '.']
            if len(cells) != len(set(cells)):
                raise InvalidSoduku()
        
        def validate_row():
            [one_to_nine([board[i][j] for j in rg]) for i in rg]

        def validate_column():
            [one_to_nine([board[i][j] for i in rg]) for j in rg]

        def validate_subbox():
            for box_x in srg:
                for box_y in srg:
                    one_to_nine([
                        board[box_x * 3 + sub_x][box_y * 3 + sub_y]
                        for sub_x in range(3)
                        for sub_y in range(3)
                    ])

        try:
            validate_column()
            validate_row()
            validate_subbox()
            return True
        except InvalidSoduku:
            return False
