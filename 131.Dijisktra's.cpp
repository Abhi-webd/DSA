#include <bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<pair<int,int>> *l;

    public: 
    graph(int v){
        this->v = v;
        l = new list<pair<int,int>>[v];
    }

    void addEdge(int x, int y , int wt , bool undir = true){
        l[x].push_back({wt,y});
        if(undir){
            l[y].push_back({wt,x});
        }
    }

    void print(){
        for(int i = 0 ; i < v  ;i++){
            cout<<i<<" --> ";
            for(auto nbr : l[i]){
                cout<<nbr.second<<" ";
            }
            cout<<endl;
        }
    }

    int dijkstra(int src,int dest){
        //data structure
        vector<int> dist(v,1000);
        set<pair<int,int>> s;

        dist[src] = 0;
        s.insert({0,src});
        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distTillNow =  it->first;

            s.erase(it); //equivalent to pop

            //iterate over nbrs

            for(auto nbrPair : l[node]){
                int nbr = nbrPair.second;
                int currentEdge = nbrPair.first;

                if(distTillNow+currentEdge < dist[nbr]){
                    //remove if pair already exist to update
                    auto f =  s.find({dist[nbr],nbr});
                    if(f != s.end()){
                        s.erase(f);
                    }

                    dist[nbr] = distTillNow+currentEdge;
                    s.insert({dist[nbr],nbr});
                }
            } 
        }
        for(int i = 0 ; i < v ; i++){
            cout<<"Node "<<i<<" distance --> "<<dist[i]<<endl;
        }
        return  dist[dest];
    }
};

int main()
{
    graph g(5);
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);
    cout<<g.dijkstra(0,4)<<endl;
    return 0;
}
