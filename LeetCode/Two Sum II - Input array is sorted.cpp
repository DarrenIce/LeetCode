class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if (numbers.size()<2)
            return vector<int>{};
        int l=0,r=numbers.size()-1;
        while (l<r) {
            if (numbers[l]+numbers[r]==target)
                return vector<int>{l+1,r+1};
            else if (numbers[l]+numbers[r]>target)
                r--;
            else
                l++;
        }
        return vector<int>{0,0};
    }
};