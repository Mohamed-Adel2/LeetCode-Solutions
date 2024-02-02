class Solution {
    public int majorityElement(int[] nums) {
          int number = nums[0];
          int cnt = 1;
          for(int i =1;i<nums.length;i++){
            if(cnt == 0)
                number = nums[i];
            if(number == nums[i])
                ++cnt;
            else
                --cnt;
            
          }
          return number;
    }
}