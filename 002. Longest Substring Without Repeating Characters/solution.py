#!python3


class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        rlen = 0
        start = 0
        trace = {}
        for index, ch in enumerate(s):
            if ch in trace and trace[ch] >= start:
                rlen = max(rlen, index - start)
                start = trace[ch] + 1
            trace[ch] = index
        return max(rlen, len(s) - start)


if __name__ == "__main__":
    print(Solution().lengthOfLongestSubstring("abcabcbb") == 3)
    print(Solution().lengthOfLongestSubstring("abba") == 2)
    print(Solution().lengthOfLongestSubstring("pwwkew") == 3)
