class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int area=0,maxarea=0;
        stack<int> s;
        int i=0;
        while (i<heights.size())
        {
            if (s.empty()||heights[i]>heights[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int top=s.top();
                s.pop();
                area=heights[top]*(s.empty()?i:i-s.top()-1);
                maxarea=max(area,maxarea);
            }
        }
        return maxarea;
    }
};