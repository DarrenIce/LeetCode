class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s=gas.size();
        int g=0;
        int start=0;
        for (int i=0;i<s*2;i++) {
            g+=gas[i%s]-cost[i%s];
            if (g<0) {
                g=0;
                start=i+1;
            }
            else if (i-start+1>=s)
                return start%s;
        }
        return -1;
    }
};