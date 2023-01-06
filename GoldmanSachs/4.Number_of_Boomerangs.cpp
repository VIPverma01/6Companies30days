/*
link: https://leetcode.com/problems/number-of-boomerangs/
*/

class Solution {
public:
    double dist(int x1, int y1, int x2, int y2){
        return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& pnts) {
        int n = pnts.size(), res = 0;
        for(int i=0;i<n;i++){
            unordered_map<double,int> mp;
            for(int j=0;j<n;j++){
                double d = dist(pnts[i][0],pnts[i][1],pnts[j][0],pnts[j][1]);
                mp[d]++;
            }
            for(auto& it : mp){
                int k = it.second-1;
                k = ((k)*(k+1))/2;
                res += 2*k;
            }
        }
        return res;
    }
};