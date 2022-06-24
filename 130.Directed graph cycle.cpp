bool dfs(int node,vector<bool> &visited,vector<bool> &stack){
        visited[node] = true;
        stack[node] = true;

        //check for backedge
        for(auto nbr:l[node]){
            if(stack[nbr]){
                return true;
            }
            else if(visited[nbr] == false){
                bool nbrFoundCycle = dfs(nbr,visited,stack);
                if(nbrFoundCycle){
                    return true;
                }
            }
        }

        //going back
        stack[node] = false;
        return false;
    }

    bool contiansCycle(){
        vector<bool> visited(v,false);
        vector<bool> stack(v,false);

        for(int i = 0 ; i < v ;i++){
             if(!visited[i]){
                if(dfs(i,visited,stack)){
                    return true;
                }
             }
        }
        return false;
    }
