/*
link: https://leetcode.com/problems/max-points-on-a-line/
*/

class Solution {
public:
    int maxPoints(vector<vector<int>>& pnts) {
        int n = pnts.size(), res = 1;
        for(int i=0;i<n;i++){
            int x1 = pnts[i][0], y1 = pnts[i][1];
            unordered_map<double,int> mp;
            for(int j=i+1;j<n;j++){
                int x2 = pnts[j][0], y2 = pnts[j][1];
                double d = (double)(x2-x1);
                double slope = (double)(y2-y1);
                if(d==0) slope = INT_MAX;
                else slope /= d;
                mp[slope]++;
            }
            for(auto& it : mp){
                res = max(res,it.second+1);
            }
        }
        return res;
    }
};