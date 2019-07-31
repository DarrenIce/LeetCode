class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==0)
            return vector<vector<int>>{};
        vector<vector<int>> nitv;
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int>b){return *a.begin()<*b.begin();});
        nitv.push_back(intervals[0]);
        for (int i=1;i<intervals.size();i++)
        {
            if (nitv.back()[1]<intervals[i][0])
                nitv.push_back(intervals[i]);
            else
            {
                nitv.back()[1]=max(nitv.back()[1],intervals[i][1]);
            }
        }
        return nitv;
    }
};