class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        low,high=0,len(nums)-1
        l,r=-1,-1
        while low<=high:
            mid=(low+high)//2
            if nums[mid]==target:
                l=r=mid
                while l!=0 and nums[l-1]==nums[l]:
                    l-=1
                while r<(len(nums)-1) and nums[r+1]==nums[r]:
                    r+=1
                return [l,r]
            if nums[mid]>target:
                high=mid-1
            else:
                low=mid+1
        return [-1,-1]