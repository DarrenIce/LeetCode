class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size()==0||nums.size()==1)
            return 0;
        int maxlen=nums[0];
        int curmax=nums[0];
        int n=nums.size();
        int step=1;
        for (int i=1;i<=min(n,maxlen);i++)
        {
            curmax=max(curmax,i+nums[i]);
            if (i==n-1)
                return step;
            if (i==maxlen)
            {
                maxlen=curmax;
                step++;
            }
        }
        return 0;
    }
};