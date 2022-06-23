void dfsHelper(int node, bool* visited){
        visited[node] = true;
        cout<<node<<" ";
        //call on all its unvisited neighbour
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
        return;
    }

    void dfs(int source){
        bool* visited = new bool[v]{0};
        dfsHelper(source,visited);
    }
