class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++)
            map.put(nums[i], i);
        
        
        for(int i = 0; i < nums.length; i++){
            int redu = target - nums[i];
            
            if(map.containsKey(redu) && map.get(redu) != i){
                return new int[] {i, map.get(redu)};
            }
        }
        return new int[] { 0, 0 };
    }
}
