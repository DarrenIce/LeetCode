class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> temp;
        for (int i=0;i<=nums.size();i++)
        {
            bt(nums,i,0,temp,sets);
        }
        return sets;
    }
    void bt(vector<int>& nums,int a,int b,vector<int>& temp,vector<vector<int>>& sets)
    {
        if (a==temp.size())
            sets.push_back(temp);
        else
        {
            for (int i=b;i<nums.size();i++)
            {
                int t=nums[i];
                temp.push_back(t);
                bt(nums,a,i+1,temp,sets);
                temp.pop_back();
            }
        }
    }
};