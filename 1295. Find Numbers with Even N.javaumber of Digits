class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for (int i : nums) {
            int r = 0;
            while (i != 0){
                i /= 10;
                r++;
            }
            if (r%2==0) count++;
        }
        return count;
    }
}