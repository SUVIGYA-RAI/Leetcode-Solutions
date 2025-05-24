class Solution {
    public boolean isPalindrome(String s) {
        char [] arr = s.toCharArray();
        StringBuffer s1 = new StringBuffer("");
        for (char c: arr){
            if (Character.isLetterOrDigit(c)){
                s1.append(c);
            }
        }
        s=s1.toString();
        s1.reverse();
        if (s1.toString().equalsIgnoreCase(s)){
            return true;
        }
        else {
            return false;
        }
    }
}