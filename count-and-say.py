from itertools import groupby

class Solution(object):
    cache = {}
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        
        # 'AAAABBBCCD' -> [[4, 'A'], [3, 'B'], [2, 'C'], [1, 'D']]
        group = lambda _str: [[len(list(g)), k] for k, g in groupby(_str)]

        # [4, 'A'] -> '4A'
        make_phrase = lambda _arr: ''.join(map(str, _arr))

        # 'AAAABBBCCD' -> '4A3B2C1D'
        make_sentence = lambda _str: ''.join(make_phrase(g) for g in group(_str))
        
        s = '1'
        for i in range(n - 1):
            s = make_sentence(s)
        return s

        
if __name__ == "__main__":
    solution = Solution()
    for i in range(10):
        print(solution.countAndSay(i))
