// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    void cycle(int src, int V , vector<int> adj[] , vector<int> &node, vector<int> &indeg){
        queue<int> q;
        for(int i = 0 ; i < V ; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            node.push_back(x);
            for(auto i : adj[x]){
                indeg[i]--;
                if(indeg[i] == 0){
                    q.push(i);
                }
            }
        }
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indeg(V,0);
        vector<int>  node;
        
        for(int i = 0 ; i < V ; i++){
            for(auto j : adj[i]){
                indeg[j]++;
            }
        }
        
        cycle(0,V,adj,node,indeg);
        if(node.size() != V){
            return true;
        }
        return false;
        
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
