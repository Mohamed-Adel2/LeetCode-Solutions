class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        sz = len(nums)
        k %= sz
        nums.reverse()
        nums[0:k] = nums[0:k][::-1]
        nums[k:] = nums[k:][::-1]