#include <bits/stdc++.h>
using namespace std;

// class graph{
//     int v;
//     list<int> *l;
//     public:
//     graph(int v){
//         this->v = v;
//         l = new list<int>[v];
//     }

//     void addEdge(int i , int j , bool undir = true){
//         l[i].push_back(j);
//         if(undir){
//             l[j].push_back(i);
//         }
//     }

//     void printAdlist(){
//         for(int i = 0 ; i < v ; i++){
//             cout<<i<<" --> ";
//             for(auto node:l[i]){
//                 cout<<node<<" ";
//             }
//             cout<<endl;
//         }
//     }

// };

class node{
    public:
    string name;
    list<string> nbrs;
    node(string name){
        this->name = name;
    }
};

class graph{
    unordered_map<string,node*> m;
    public:
    graph(vector<string> cities){
         for(auto city:cities){
            m[city]  = new node(city);
         }
    }

    void addEdge(string x, string y , bool undir = false){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void printadjlist(){
        for(auto cityPair : m){
            auto city = cityPair.first;
            node* n = cityPair.second;
            cout<<city<<" --> ";
            for(auto nbr : n->nbrs){
                cout<<nbr<<" ";
            }
            cout<<endl; 
        }
        
    }
};

int main()
{
    vector<string> cities = {"delhi","london","paris","newyork"};
    graph g(cities);
    g.addEdge("delhi","london");
    g.addEdge("newyork","london");
    g.addEdge("delhi","paris");
    g.addEdge("paris","newyork");
    g.printadjlist();
    return 0;
}
