class Solution(object):
    def subsetXORSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        size, ans = len(nums), 0
        for i in range(0, 1 << size):
            sub_ans = 0
            for j in range(0, size):
                if i & (1 << j):
                    sub_ans ^= nums[j]
            ans += sub_ans
        return ans
        