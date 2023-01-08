/*
link: https://leetcode.com/problems/count-nice-pairs-in-an-array/
*/

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size(), mod = 1e9+7;
        long long res = 0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int c = nums[i], rev = 0;
            while(c){    
                int rem=c%10;      
                rev=rev*10+rem;    
                c/=10;    
            }
            res += mp[nums[i]-rev];
            mp[nums[i]-rev]++;
            res %= mod;
        }
        return res;
    }
};