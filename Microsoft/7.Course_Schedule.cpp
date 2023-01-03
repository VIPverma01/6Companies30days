/*
link: https://leetcode.com/problems/course-schedule/
*/

class Solution {
public:
    bool dfs(vector<int> adj[], int v, vector<bool>& vis, vector<bool>& vis2){
        if(vis2[v]) return false;
        if(vis[v]) return true;
        vis[v] = true;
        vis2[v] = true;
        for(auto i : adj[v]){
            bool b = dfs(adj,i,vis,vis2);
            if(!b) return false;
        }
        vis2[v] = false;
        return true;
    }
    
    bool dfscoloring(vector<int> adj[], int v, vector<int>& vis){
        if(vis[v]==1) return false;
        if(vis[v]==2) return true;
        vis[v] = 1;
        for(auto i : adj[v]){
            bool b = dfscoloring(adj,i,vis);
            if(!b) return false;
        }
        vis[v] = 2;
        return true;
    }
    
    bool canFinish(int n, vector<vector<int>>& pre) {
        // Topological Sort based question
        vector<int> adj[n];
        vector<int> ind(n);
        for(auto e : pre){
            if(e[0]==e[1]) return false;
            adj[e[1]].push_back(e[0]);
            ind[e[0]]++;
        }

        // Method 1: Using DFS

        // vector<bool> vis(n,false);
        // vector<bool> vis2(n,false);
        // bool f = false;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         f = true;
        //         bool b = dfs(adj,i,vis,vis2);
        //         if(!b) return false;
        //     }
        // }
        // if(f) return true;
        // return false;
        

        // Method 2: Using DFS Coloring(with one vis array)
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                bool b = dfscoloring(adj,i,vis);
                if(!b) return false;
            }
        }
        return true;

        
        // Method 3: Using BFS
        
        // vector<bool> vis(n,false);
        // queue<int> q;
        // for(int i=0;i<n;i++){
        //     if(ind[i]==0) q.push(i);
        // }
        // int res = 0;
        // while(!q.empty()){
        //     int c = q.front();
        //     q.pop();
        //     if(vis[c]) return {};
        //     vis[c] = true;
        //     res++;
        //     for(auto i : adj[c]){
        //         ind[i]--;
        //         if(ind[i]==0) q.push(i);
        //     }
        // }
        // return res==n;
    }
};