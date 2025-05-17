class Solution:
    def canJump(self, nums: List[int]) -> bool:
        arr = [0 for i in range(len(nums) + 1)]
        for i in range(len(nums)):
            arr[min(i + 1, len(nums))] += 1
            arr[min(i + nums[i] + 1, len(nums))] -= 1
        for i in range(1, len(arr) - 1):
            arr[i] += arr[i - 1]
            if arr[i] == 0:
                return False
        return True