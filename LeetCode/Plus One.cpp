class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        bool goon=false;
        for (int i=n-1;i>=0;i--)
        {
            digits[i]++;
            if (digits[i]==10)
            {
                digits[i]=0;
                goon=true;
            }    
            else
            {
                goon=false;
                break;
            }
        }
        if (digits[0]==0&&goon)
        {
            auto i =digits.begin();
            digits.insert(i,1);
        }
        return digits;
    }
};