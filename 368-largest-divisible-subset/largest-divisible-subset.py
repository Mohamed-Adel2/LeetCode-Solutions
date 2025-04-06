from math import sqrt

class Solution(object):
    def largestDivisibleSubset(self, nums):
        nums = sorted(nums)
        prev_divisor = {}
        for i in range (0, len(nums)):
            prev_divisor[i] = [i, 1]
            for j in range(0, i):
                if nums[i] % nums[j] == 0 and prev_divisor[i][1] < prev_divisor[j][1] + 1:
                    prev_divisor[i][0], prev_divisor[i][1] = j, prev_divisor[j][1] + 1
        mx_sz, idx = 0, 0
        for i in range (0, len(nums)):
            if mx_sz < prev_divisor[i][1]:
                mx_sz, idx = prev_divisor[i][1], i
        ans = [nums[idx]]
        while prev_divisor[idx][0] != idx:
            ans.append(nums[prev_divisor[idx][0]])
            idx = prev_divisor[idx][0]
        return ans
        