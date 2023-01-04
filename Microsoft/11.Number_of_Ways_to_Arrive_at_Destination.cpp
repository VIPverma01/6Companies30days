/*
link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<pair<int,int>> adj[n];
        for(auto& r : roads){
            adj[r[0]].push_back({r[1],r[2]});
            adj[r[1]].push_back({r[0],r[2]});
        }
        vector<pair<long long,long long>> dist(n,{LONG_LONG_MAX,0});
        vector<bool> vis(n,false);
        dist[0] = {0,1};
        while(true){
            long long v=-1, mx = LONG_LONG_MAX;
            for(int i=0;i<n;i++){
                if(!vis[i] && dist[i].first<mx){
                    mx = dist[i].first;
                    v = i;
                }
            }
            if(v==-1) break;
            vis[v] = true;
            long long d = dist[v].first, w = dist[v].second;
            for(auto i : adj[v]){
                if(dist[i.first].first>d+i.second){
                    dist[i.first] = {d+i.second,w};
                }
                else if(dist[i.first].first>=d+i.second){
                    dist[i.first].second += w;
                    dist[i.first].second %= mod;
                }
            }
        }
        return dist[n-1].second%mod;
    }
};