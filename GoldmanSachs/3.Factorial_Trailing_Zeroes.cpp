/*
link: https://leetcode.com/problems/factorial-trailing-zeroes/
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0, c = 5;
        while(c<=n){
            res += n/c;
            c *= 5;
        }
        return res;
    }
};