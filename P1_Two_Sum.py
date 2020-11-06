class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        HashMap = {}
        for i, n in enumerate(nums) :
            l = target - n
            if l in HashMap :
                return [HashMap[l], i]
            HashMap[n] = i
        return 
