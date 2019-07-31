class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low,high=0,len(nums)-1
        while low<=high:
            mid=(low+high)//2
            if target==nums[mid]:
                return mid
            if target<nums[mid]:
                high=mid-1
            else:
                low=mid+1
        if low<len(nums) and nums[low]<target:
            return low+1
        else:
            return low