/*
link: https://leetcode.com/problems/rotate-function/
*/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int res = INT_MIN, n = nums.size(), curVal = 0, sum = 0;
        for(int i=0;i<n;i++){
            curVal += i*nums[i];
            sum += nums[i];
        }
        res = curVal;
        for(int i=n-1;i>0;i--){
            // curVal -= (n-1)*nums[i]; // current element is multiplies with zero which was multiplied by (n-1) in last turn
            // curVal += (sum-n*nums[i]); // occurrences of each number increase by 1 in comparision to last turn
            curVal += (sum-n*nums[i]);
            res = max(res,curVal);
        }
        return res;
    }
};