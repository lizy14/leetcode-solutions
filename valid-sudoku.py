class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """

        def _and(arr):
            for a in arr:
                if not a:
                    return False
            return True

        rg = range(9)

        def one_to_nine(arr):
            def count(arr, i):
                return len(list(filter(lambda x: x == i, arr)))
            return _and(count(arr, str(i + 1)) <= 1 for i in rg)
        
        def validate_row(i):
            return one_to_nine([board[i][j] for j in rg])

        def validate_column(j):
            return one_to_nine([board[i][j] for i in rg])
            
        def get_coord(id):
            return (id % 3, id // 3)

        def validate_subbox(box_id):
            def get_cell(box_id, sub_id):
                (sub_x, sub_y) = get_coord(sub_id)
                (box_x, box_y) = get_coord(box_id)
                return board[box_x * 3 + sub_x][box_y * 3 + sub_y]
            cells = [get_cell(box_id, sub_id) for sub_id in rg]
            return one_to_nine(cells)

        columns = _and([validate_column(i) for i in rg])
        rows = _and([validate_row(i) for i in rg])
        subboxes = _and([validate_subbox(i) for i in rg])

        return _and([columns, rows, subboxes])
        
