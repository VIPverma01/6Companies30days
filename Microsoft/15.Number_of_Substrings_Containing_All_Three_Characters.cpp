/*
link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
*/

class Solution {
public:
    int numberOfSubstrings(string s) {
        
        // Method 1: Sliding window
        
        // int n = s.size(), cnt[3] = {0}, i = 0, j = 0, res = 0;
        // while(j<n){
        //     cnt[s[j]-'a']++;
        //     while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) --cnt[s[i++]-'a'];
        //     res += i;
        //     j++;
        // }
        // return res;
        
        
        // Method 2: By storing last occurrences of each character
        
        int n = s.size(), last[3] = {-1,-1,-1}, res = 0;
        for(int i=0;i<n;i++){
            last[s[i]-'a'] = i;
            res += min(last[0],min(last[1],last[2]))+1;
        }
        return res;
    }
};