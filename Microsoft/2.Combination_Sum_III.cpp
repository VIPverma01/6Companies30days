/*
link: https://leetcode.com/problems/combination-sum-iii/
*/

class Solution {
public:
    vector<vector<int>> res;
    
    void rec(int k, int n, int last, vector<int> v){
        if(last!=10) v.push_back(last);
        if(k==0) {
            if(n==0) res.push_back(v); return;
        }
        for(int i=max(1,n/k);i<min(n+1,last);i++) rec(k-1,n-i,i,v);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        rec(k,n,10,{});
        return res;
    }
};