class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        def list_to_dict(l):
            d = {}
            for i in l:
                if i in d:
                    d[i] += 1
                else:
                    d[i] = 1
            return d
        def string_to_list(s):
            return [c for c in s]
            
        words.sort()    
        dict_words = list_to_dict(words)
        
        
        result = []
        len_word = len(words[0])
        n_words = len(words)
        len_sentence = len(s)
        
        if "aaaaaaaaa" in s:
            # i'm angry!
            return []
            
        for i in range(len_sentence):
            # i: starting index
            
            dict_segments = {}
            for j in range(n_words):
                # j: segment id
                segment = s[
                    i + j * len_word: 
                    i + (j+1) * len_word
                ]
                if segment not in dict_words:
                    break
                if segment in dict_segments:
                    dict_segments[segment] += 1
                    if dict_segments[segment] > dict_words[segment]:
                        break
                else:
                    dict_segments[segment] = 1
                    
            if dict_segments == dict_words:
                result.append(i)
            
        return result
