class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        single = 0
        for num in nums:
            single ^= num
        return single


# test
if __name__ == '__main__':
    print(Solution().singleNumber([2, 4, 5, 4, 5, 2, 6, 7, 7]))
