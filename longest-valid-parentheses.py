class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        '''
        dynamic programming
        a[i]: length of longest valid string ending at s[i]
        
        ....((...))
        -m-| |-l-|
           kp    ji
        '''
        r = 0  # result
        a = [0] * len(s)
        
        for i, c in enumerate(s):
            if c == ')':
                j = i - 1
                l = a[j] if j >= 0 else 0
                p = i - l - 1
                if p < 0 or s[p] == ')':
                    continue
                k = i - l - 2
                m = a[k] if k >= 0 else 0
                a[i] = m + l + 2
                r = max(r, a[i])
        
        return r
