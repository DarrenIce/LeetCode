class Solution {
public:
    void dfs(int n,int k,vector<int>& nums,int& count) {
        if (n==k) {
            ++count;
        } else {
            for (int i=k;i<n;i++) {
                swap(nums[i],nums[k]);
                if ((nums[k]%(k+1)==0)||((k+1)%nums[k]==0))
                    dfs(n,k+1,nums,count);
                swap(nums[i],nums[k]);
            }
        }
    }
    int countArrangement(int N) {
        if (N==0)
            return 0;
        int count=0;
        vector<int> nums(N,1);
        for (int i=0;i<N;i++)
            nums[i]=i+1;
        dfs(N,0,nums,count);
        return count;
    }
};