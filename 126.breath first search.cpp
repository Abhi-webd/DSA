#include <bits/stdc++.h>
using namespace std;

class graph{
    int v;
    list<int> *l;
    public:
    graph(int v){
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j , bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void bfs(int source){
        vector<bool> visited(v,false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout<<temp<<" ";
            for(auto node:l[temp]){
                if(visited[node] == false){
                    q.push(node);
                    visited[node] = true;
                }
            }
        }
    }
};

int main()
{
    graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);

    g.bfs(1);
    return 0;
}
