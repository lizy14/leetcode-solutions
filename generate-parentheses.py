class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        return self._generateParenthesis("", n, n)
    
    def _generateParenthesis(self, prefix, left, right):
        # left/right: expected in suffix
        
        result = []
        
        if left == 0 and right == 0:
            result.append(prefix)
        
        if left > 0: 
            result += self._generateParenthesis(prefix + '(', left-1, right)
        
        if right > 0 and right > left:
            result += self._generateParenthesis(prefix + ')', left, right-1)
        
        return result
