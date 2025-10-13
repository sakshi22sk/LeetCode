class Solution:
    def removeAnagrams(self, words):
        res = [words[0]]
        for i in range(1, len(words)):
            # If current word is not an anagram of previous kept word
            if sorted(words[i]) != sorted(words[i - 1]):
                res.append(words[i])
        return res
