/*
link: https://leetcode.com/problems/largest-divisible-subset/
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        // 1st mmethod using dp array of vector

        // vector<vector<int>> dp(n);
        // sort(nums.begin(),nums.end());
        // int mxSize = 0, indAns = 0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i;j++){
        //         if(nums[i]%nums[j]==0 && dp[j].size()>dp[i].size()){
        //             dp[i] = dp[j];
        //         }
        //     }
        //     dp[i].push_back(nums[i]);
        //     if(dp[i].size()>mxSize){
        //         mxSize = dp[i].size();
        //         indAns = i;
        //     }
        // }
        // return dp[indAns];
        

        // 2nd method using dp array of int and parent vector
        vector<int> dp(n,1);
        vector<int> par(n,-1);
        sort(nums.begin(),nums.end());
        int mxSize = 0, indAns = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    par[i] = j;
                }
            }
            if(dp[i]>mxSize){
                mxSize = dp[i];
                indAns = i;
            }
        }
        vector<int> res;
        while(indAns!=-1){
            res.push_back(nums[indAns]);
            indAns = par[indAns];
        }
        return res;
    }
};