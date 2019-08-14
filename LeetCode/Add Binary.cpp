class Solution {
public:
    string addBinary(string a, string b) {
        int c1=a.size();
        int c2=b.size();
        int n=c1>c2?c1:c2;
        string sum;
        int add=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for (int i=0;i<n;i++) {
            int n1=i<c1?a[i]-'0':0;
            int n2=i<c2?b[i]-'0':0;
            int n=(n1+n2+add)%2;
            add=(n1+n2+add)/2;
            sum=to_string(n)+sum;
        }
        if (add>0)
            sum='1'+sum;
        return sum;
    }
};