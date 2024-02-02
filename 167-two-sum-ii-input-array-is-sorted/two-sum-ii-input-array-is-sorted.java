class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int ptr1 = 0, ptr2 = numbers.length - 1;
        while (ptr1 < ptr2) {
            if (numbers[ptr1] + numbers[ptr2] == target)
                return new int[]{++ptr1, ++ptr2};
            else if (numbers[ptr1] + numbers[ptr2] < target)
                ++ptr1;
            else
                --ptr2;
        }
        return new int[]{0, 0};
    }
}