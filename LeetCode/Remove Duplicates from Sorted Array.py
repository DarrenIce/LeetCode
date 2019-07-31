class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        length=0
        l=len(nums)
        i=0
        while i<l:
            if i==0 or nums[i]!=nums[i-1]:
                length+=1
                i+=1
            else:
                del nums[i]
                l-=1
        return length