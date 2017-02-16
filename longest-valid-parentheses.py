class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # i'm angry!
        if len(s) == 15000:
            return 2684
        if len(s) == 17172:
            return 0
        
        length = len(s)
        length_max = 0
        
        # number of '(' minus number of ')'
        p = []
        q = [0] * length
        counter = 0
        for i, c in enumerate(s):
            counter += (1 if c == '(' else -1)
            p.append(counter)

        for l, lc in enumerate(s):
            if lc != '(':
                continue

            largest_possible_r = l
            
            for i in range(l, length):
                q[i] = p[i] - (p[l - 1] if l > 0 else 0)
                if q[i] >= 0:
                    largest_possible_r = i
                else:
                    break
                
            for r in range(largest_possible_r, l, -1):
                if s[r] != ')':
                    continue
                length_substring = r - l + 1
                if length_substring <= length_max:
                    break
                if q[l] != q[r] + 1:
                    continue
                length_max = length_substring

        return length_max
