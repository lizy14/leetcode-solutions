from itertools import groupby

class Solution(object):
    cache = {}
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """

        s = '1'
        for i in range(n - 1):
            s = self.read(s)
        return s

    def read(self, s):
        """
        :type n: str
        :rtype: str
        """
        
        # 'AAAABBBCCD' -> [[4, 'A'], [3, 'B'], [2, 'C'], [1, 'D']]
        group = lambda x: [[len(list(g)), k] for k, g in groupby(s)]

        # [4, 'A'] -> '4A'
        make_phrase = lambda x: ''.join(map(str, x))
        
        return ''.join(make_phrase(g) for g in group(s))


        
if __name__ == "__main__":
    solution = Solution()
    assert(solution.read('1211') == '111221')
    for i in range(10):
        print(solution.countAndSay(i))
