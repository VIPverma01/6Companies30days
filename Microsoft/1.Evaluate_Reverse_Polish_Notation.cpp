/* 
link: https://leetcode.com/problems/evaluate-reverse-polish-notation/ 
*/

class Solution {
public:
    #define ll long long
    
    int evalRPN(vector<string>& t) {
        stack<ll> st;
        int n = t.size();
        for(int i=0;i<n;i++){
            // push into the stack if t[i] is a number
            if(t[i]!="*" && t[i]!="-" && t[i]!="+" && t[i]!="/"){
                ll k = std::stoi(t[i]);
                st.push(k);
            }
            // evaluate top two numbers in stack according to the operator and push result in stack
            else{
                ll a = st.top();
                st.pop();
                ll b = st.top();
                st.pop();
                if(t[i]=="+") a += b;
                else if(t[i]=="-") a = b-a;
                else if(t[i]=="*") a *= b;
                else a = b/a;
                st.push(a);
            }
        }
        return st.top();
    }
};