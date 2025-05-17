class Solution:
    def sortColors(self, nums: List[int]) -> None:
        cnt = [0, 0, 0]
        for num in nums:
            cnt[num] += 1
        for idx, num in enumerate(nums):
            if cnt[0]:
                nums[idx] = 0
                cnt[0] -= 1
            elif cnt[1]:
                nums[idx] = 1
                cnt[1] -= 1
            else:
                nums[idx] = 2

        