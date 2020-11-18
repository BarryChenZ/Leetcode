class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(s.length() <= 1) return s.length();
        int i = 0, j = 0, ans = 0;
        while(i <= j && j < n){
            String tmp = s.substring(i, j + 1);
            j++;
            while(j < n && !tmp.contains(Character.toString(s.charAt(j)))){
                tmp += s.charAt(j++);
            }
            ans = Math.max(ans, j - i);
            if(j < n){
                int pos = tmp.indexOf(s.charAt(j));
                i = i + pos + 1;
            }
        }
        return ans;
    }
}
