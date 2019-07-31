class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        buff={}
        for i in range(len(nums)):
            if nums[i] in buff:
                return [buff[nums[i]],i]
            else:
                buff[target-nums[i]]=i