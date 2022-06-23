void shortestPath(int source,int dest){
        vector<bool> visited(v,false);
        vector<int> sd(v,0);
        vector<int> p(v,-1 );
        queue<int> q;
        q.push(source);
        visited[source] = true;
        sd[source] = 0;
        p[source] = source;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            // cout<<temp<<" ";
            for(auto node:l[temp]){
                if(visited[node] == false){
                    q.push(node);
                    //parent and dist update
                    p[node] = temp;
                    sd[node] = sd[temp]+1;
                    visited[node] = true;
                }
            }
        }
        //print shortest distance
        for(int i = 0 ; i < v ; i++){
            cout<<"shortest distance to "<<i<<" is "<<sd[i]<<endl;
        }

        //printing shortest path 
        if(dest != -1){
            int temp =  dest;
            while(temp != source){
                cout<<temp<<" --> ";
                temp = p[temp];
            }
            cout<<source<<endl; 
        }
    }
