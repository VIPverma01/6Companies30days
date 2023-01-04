/*
link: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        // Method 1: Using RightMin and LeftMax array
        
        // int n = nums.size();
        // vector<int> leftMax(n), rightMin(n);
        // leftMax[0] = nums[0]; rightMin[n-1] = nums[n-1];
        // for(int i=1;i<n;i++) leftMax[i] = max(leftMax[i-1],nums[i]);
        // for(int i=n-2;i>=0;i--) rightMin[i] = min(rightMin[i+1],nums[i]);
        // int leftInd = 0, rightInd = n-1;
        // while(leftInd<n){
        //     if(nums[leftInd]!=leftMax[leftInd] || nums[leftInd]!=rightMin[leftInd]) break;
        //     leftInd++;
        // }
        // while(rightInd>=0){
        //     if(nums[rightInd]!=leftMax[rightInd] || nums[rightInd]!=rightMin[rightInd]) break;
        //     rightInd--;
        // }
        // return rightInd-leftInd>0 ? rightInd-leftInd+1 : 0;
        
        
        
        
        // Method 2: Using monotonic stack
        
        // int n = nums.size();
        // stack<int> left,right;
        // int l = n, r = 0;
        // for(int i=0;i<n;i++){
        //     while(!left.empty() && nums[left.top()]>nums[i]) {
        //         l = min(l,left.top()); 
        //         left.pop();
        //     }
        //     left.push(i);
        // }
        // for(int i=n-1;i>=0;i--){
        //     while(!right.empty() && nums[right.top()]<nums[i]) {
        //         r = max(r,right.top()); 
        //         right.pop();
        //     }
        //     right.push(i);
        // }
        // return max(r-l+1,0);
        

        
        
        // Method 3: Without using Arrays but just pointers and variables
        
        int n = nums.size();
        int mx = INT_MIN , r = -1;
        for(int i=0;i<n;i++){
            if(nums[i]<mx){
                r = i;
            }
            else{
                mx = nums[i];
            }
        }
        
        int mn = INT_MAX , l = n;
        for(int i=n-1;i>=0;i--){
            if(nums[i]>mn){
                l = i;
            }
            else{
                mn = nums[i];
            }
        }
        return max(0,r-l+1);
    }
};