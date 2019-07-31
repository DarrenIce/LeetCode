class Solution:
    def threeSum(self,nums,target):
        nums.sort()
        result=[]
        for i in range(len(nums)):
            if nums[i]==nums[i-1] and i!=0:
                continue
            l,r=i+1,len(nums)-1
            while l<r:
                sum=nums[i]+nums[l]+nums[r]
                if sum<target:
                    l+=1
                elif sum>target:
                    r-=1
                else:
                    result.append([nums[i],nums[l],nums[r]])
                    while l<r and nums[l]==nums[l+1]:
                        l+=1
                    while l<r and nums[r]==nums[r-1]:
                        r-=1
                    l+=1
                    r-=1
        return result
    
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        result=[]
        for i in range(len(nums)-3):
            if nums[i]==nums[i-1] and i!=0:
                continue
            threeres=self.threeSum(nums[i+1:],target-nums[i])
            for item in threeres:
                result.append([nums[i]]+item)
        return result