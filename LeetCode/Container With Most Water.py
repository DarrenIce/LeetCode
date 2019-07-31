class Solution:
    def maxArea(self, height: List[int]) -> int:
        left,right=0,len(height)-1
        maxarea=min(height[left],height[right])*(right-left)
        while right>left:
            if height[left]<height[right]:
                left=left+1
            else:
                right=right-1
            maxarea=max(min(height[left],height[right])*(right-left),maxarea)
        return maxarea