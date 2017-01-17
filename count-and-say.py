from itertools import groupby

class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n <= 1:
            return '1'
        return self.read(self.countAndSay(n - 1))

    def read(self, s):
        # 'AAAABBBCCD' -> '4A3B2C1D'
        
        # 'AAAABBBCCD' -> [[4, 'A'], [3, 'B'], [2, 'C'], [1, 'D']]
        group = lambda x: [[len(list(g)), k] for k, g in groupby(s)]

        # [4, 'A'] -> '4A'
        make_phrase = lambda x: ''.join(map(str, x))
        
        return ''.join(make_phrase(g) for g in group(s))
