//这个题看似很简单，但是时间优化不容易
//需要用到哈希set和bitset
//巧妙运用了格雷码来枚举我是想不到的
//bitset的函数运用也学习到了

class Solution {
public:
    void dfs(int num,int k,bitset<6>& b,bool h,unordered_set<string>& s) {
        if (k==6) {
            if (num==b.count()) {
                if (h) {
                    if (b.to_ulong()<=11)
                        s.insert(to_string(b.to_ulong()));
                }
                else {
                    if (b.to_ulong()<=59) {
                        if (b.to_ulong()<10)
                            s.insert('0'+to_string(b.to_ulong()));
                        else
                            s.insert(to_string(b.to_ulong()));
                    }
                }
            }
        }
        else {
            dfs(num,k+1,b,h,s);
            b.flip(k);
            dfs(num,k+1,b,h,s);
        }
    }
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        for (int i=0;i<=num;i++) {
            unordered_set<string> h;
            unordered_set<string> m;
            int y=num-i;
            bitset<6> b;
            dfs(i,0,b,true,h);
            dfs(y,0,b,false,m);
            for (string x:h){
                for (string y:m) {
                    ans.push_back(x+':'+y);
                }
            }
        }
        return ans;
    }
};