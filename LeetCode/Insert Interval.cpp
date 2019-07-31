class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size()==0)
            return vector<vector<int>> {newInterval};
        vector<vector<int>> res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){return a[0]<b[0];});
        res.push_back(intervals[0]);
        for (int i=1;i<intervals.size();i++)
        {
            if (res.back()[1]<intervals[i][0])
                res.push_back(intervals[i]);
            else
            {
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};