bool CCHelper(int node, vector<bool> &visited, int parent){
        visited[node] = true;
        for(auto nbr : l[node]){
            if(!visited[nbr]){
                bool nbrFoundCycle = CCHelper(nbr,visited,node);
                if(nbrFoundCycle){
                    return true;
                }
            }
            else if(nbr != parent){
                return true;
            }
        }
        return false;
    }

    bool containsCycle(){
        vector<bool> visited(v,false);
        return CCHelper(0,visited,-1);
    }
