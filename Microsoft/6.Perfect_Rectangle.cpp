/*
link: https://leetcode.com/problems/perfect-rectangle/
*/

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& recs) {

        // Wrong/Incomplete approach by calculation Area

        // vector<int> bl = {INT_MAX,INT_MAX}, br = {INT_MIN,INT_MAX}, tl = {INT_MAX,INT_MIN}, tr = {INT_MIN,INT_MIN};
        // long long totalArea = 0;
        // for(auto& rec : recs){
        //     int x = rec[0], y = rec[1], a = rec[2], b = rec[3];
        //     totalArea += (b-y) * (a-x);
        //     if(x<=bl[0] && y<=bl[1]) {bl[0]=x; bl[1]=y;}
        //     if(a>=br[0] && y<=br[1]) {br[0]=a; br[1]=y;}
        //     if(x<=tl[0] && b>=tl[1]) {tl[0]=x; tl[1]=b;}
        //     if(a>=tr[0] && b>=tr[1]) {tr[0]=a; tr[1]=b;}
        // }
        // if(bl[0]!=tl[0] || bl[1]!=br[1] || br[0]!=tr[0] || tl[1]!=tr[1]) return false; 
        // long long newArea = (tr[0]-bl[0]) * (tr[1]-bl[1]);
        // return totalArea==newArea;
        

        // Help from discuss section : https://leetcode.com/problems/perfect-rectangle/discuss/2987814/C%2B%2B-oror-Easy-To-Understand

        map<pair<int,int>,int> mp;
        for(auto rec : recs){
            mp[{rec[0],rec[1]}]++;
            mp[{rec[2],rec[3]}]++;
            mp[{rec[0],rec[3]}]--;
            mp[{rec[2],rec[1]}]--;
        }
        int corners = 0;
        for(auto it : mp){
            if(abs(it.second)==1) corners++;
            else if(it.second!=0) return false;
        }
        
        return corners==4;
    }
};
