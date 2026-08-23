class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        vector<vector<int>> adj(n);
        
        for (auto &edge : paths) {
            int u = edge[0] - 1;
            int v = edge[1] - 1;
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> flower(n, 0);
        
        for (int node = 0; node < n; node++) {
            
            bool used[5] = {false};
            
            // Mark colors used by adjacent gardens
            for (int neighbour : adj[node]) {
                if (flower[neighbour] != 0) {
                    used[flower[neighbour]] = true;
                }
            }
            
            // Choose an unused flower
            for (int col = 1; col <= 4; col++) {
                if (used[col] == false) {
                    flower[node] = col;
                    break;
                }
            }
        }
        
        return flower;
    }
};