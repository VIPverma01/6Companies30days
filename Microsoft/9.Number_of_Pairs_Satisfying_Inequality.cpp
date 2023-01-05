/*
link: https://leetcode.com/problems/number-of-pairs-satisfying-inequality/
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;

typedef tree<pair<int,int>, null_type, less_equal<pair<int,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    long long res,n,d;
    
    void merge(vector<int>& nums, int l, int mid, int r){
        int s = r-l+1, i = l, j = mid+1;
        while(i<=mid || j<=r){
            if(i>mid) {
                j++;
                res += mid-l+1;
            }
            else if(j>r) i++;
            else if(nums[i]<=d+nums[j]) i++;
            else {
                res += i-l;
                j++;
            }
        }
        sort(nums.begin()+l,nums.begin()+r+1);
    }
    
    void mergeSort(vector<int>& nums, int l, int r){
        if(l==r) return;
        int mid = l + (r-l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {

        // Method1: using ordered_set

        // int n = nums1.size();
        // vector<int> d(n);
        // for(int i=0;i<n;i++){
        //     d[i] = (nums1[0]-nums1[i])-(nums2[0]-nums2[i]);
        // }
        // ordered_set ost;
        // long long res = 0;
        // for(int i=n-1;i>=0;i--){
        //     int k = ost.order_of_key({d[i]+diff+1,i});
        //     res += k;
        //     ost.insert({d[i],i});
        // }
        // return res;

        


        // Method 2: using reversible pair logic
        
        n = nums1.size(), res = 0, d = diff;
        vector<int>nums(n);  
        
        for(int i=0;i<n;i++) nums[i]=nums1[i]-nums2[i]; 
        
        mergeSort(nums,0,n-1);
        
        return res;
    }
};