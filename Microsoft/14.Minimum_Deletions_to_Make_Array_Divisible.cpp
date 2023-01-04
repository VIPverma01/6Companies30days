/*
link: https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/
*/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsD) {
        int n1 = nums.size(), n2 = numsD.size();
        int gcd = numsD[0];
        for(int i=1;i<n2;i++) gcd = __gcd(gcd,numsD[i]);
        sort(nums.begin(),nums.end());
        int res = 0;
        for(int i=0;i<n1;i++){
            if(gcd%nums[i]!=0) res++;
            else break;
        }
        return res==n1 ? -1 : res;
    }
};