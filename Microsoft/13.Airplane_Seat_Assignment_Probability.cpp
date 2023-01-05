/*
link: https://leetcode.com/problems/airplane-seat-assignment-probability/
*/

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n==1) return 1;
        return 0.5;
        
        
        // Explaination link: https://leetcode.com/problems/airplane-seat-assignment-probability/discuss/411905/It's-not-obvious-to-me-at-all.-Foolproof-explanation-here!!!-And-proof-for-why-it's-12
        
        // if(n == 1) return 1;
        // vector<double> dp(2, 0); dp[0] = 1.0/n;
        // for(int i = 3; i <= n; ++i)
        //     dp[0] = dp[1] = dp[0] + dp[0]/(n-i+2);
        // return 1 - dp[0];
    }
};