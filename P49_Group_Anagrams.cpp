class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if(strs.length == 0) return new ArrayList();
        Map<String, List> ans = new HashMap<String, List>();
        for(String s : strs){
            char[] c = s.toCharArray();
            Arrays.sort(c);
            String key = Arrays.toString(c);
            if(!ans.containsKey(key)) ans.put(key, new ArrayList());
            ans.get(key).add(s);
        }
        return new ArrayList(ans.values());
    }
}
