/*
link: https://leetcode.com/problems/number-of-people-aware-of-a-secret/
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
        vector<long long> v(n);
        long long c = 0, mod = 1e9+7;
        v[0] = 1;
        for(int i=1;i<n;i++){
            if(i-d>=0) c += v[i-d];
            if(i-f>=0) c -= v[i-f];
            if(c>=0)c %= mod;
            else c += mod;
            v[i] = c;
        }
        c = 0;
        for(int i=max(0,n-f);i<n;i++) {
            c+=v[i];
            c %= mod;
        }
        return c;
    }
};