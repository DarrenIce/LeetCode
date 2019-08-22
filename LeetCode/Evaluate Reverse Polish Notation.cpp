class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto tok:tokens) {
            if (tok=="+") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(a+b);
                //cout<<"a+b: "<<a+b<<endl;
            }
            else if (tok=="-") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b-a);
                //cout<<"a-b: "<<a-b<<endl;
            }
            else if (tok=="*") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(a*b);
                //cout<<"a*b: "<<a*b<<endl;
            }
            else if (tok=="/") {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                s.push(b/a);
                //cout<<"b/a: "<<b/a<<endl;
            }
            else {
                s.push(stoi(tok));
                //cout<<"push: "<<tok<<endl;
            }
        }
        return s.top();
    }
};