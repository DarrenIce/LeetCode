class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2)
            return 0;
        int minval=INT_MAX;
        int maxval=INT_MIN;
        for (auto num:nums) {
            minval=min(minval,num);
            maxval=max(maxval,num);
        }
        int bucketsize=max(1,(maxval-minval)/((int)nums.size()-1));
        int bucketnum = ceil((maxval - minval+1) / (float)bucketsize);
        vector<int> minbucket(bucketnum,INT_MAX);
        vector<int> maxbucket(bucketnum,INT_MIN);
        for (int i=0;i<nums.size();i++) {
            if (nums[i]==minval||nums[i]==maxval)
                continue;
            int index=(nums[i]-minval)/bucketsize;
            minbucket[index]=min(minbucket[index],nums[i]);
            maxbucket[index]=max(maxbucket[index],nums[i]);
        }
        int pre=minval;
        int maxgap=0;
        for (int i=0;i<bucketnum;i++) {
            if (minbucket[i]==INT_MAX||maxbucket[i]==INT_MIN)
                continue;
            maxgap=max(maxgap,minbucket[i]-pre);
            pre=maxbucket[i];
        }
        return max(maxgap,maxval-pre);
    }
};