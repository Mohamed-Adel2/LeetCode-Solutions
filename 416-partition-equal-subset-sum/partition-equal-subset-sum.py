class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        total_sum = sum(nums)
        if total_sum % 2:
            return False

        dp = [[-1 for i in range(total_sum + 1)] for j in range(len(nums) + 1)]

        return self.solve(nums, dp, 0, 0, total_sum / 2)

    def solve(self, nums, dp, idx, sum, target_sum):
        if idx >= len(nums):
            return sum == target_sum
        if sum > target_sum:
            return False
        if ~dp[idx][sum]:
            return dp[idx][sum]
        dp[idx][sum] = self.solve(nums, dp, idx + 1, sum, target_sum) or self.solve(nums, dp, idx + 1, sum + nums[idx],
                                                                                    target_sum)
        return dp[idx][sum]