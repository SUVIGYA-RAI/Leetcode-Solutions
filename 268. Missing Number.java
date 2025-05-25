class Solution {
    public int missingNumber(int[] nums) {
        int size = nums.length;
        int n = size;
        int sum = 0;
        for (int c : nums){
            sum+=c;
        }
        long s1 = ((long)n*(n+1))/2;
        return (int)(s1 - sum);
    }
}