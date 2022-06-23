#include <bits/stdc++.h>
using namespace std;

class point{
    public:
    int x;
    int y;
    point(int x,int y){
        this->x = x;
        this->y = y;
    }
};

//comp for set
class compare{
    public:
    bool operator()(const point p1,const point p2){
        if(p1.x == p2.x){
            return p1.y < p2.y;
        }

        return p1.x < p2.x; 
    }
};

int countRectangles(vector<point> points){
    set<point,compare> s;
    for(auto i : points){
        s.insert(i);
    }
    int ans =0;
    for(auto it = s.begin() ; it != prev(s.end());it++){
        for(auto jt = next(it) ; jt != s.end(); jt++){
            point p1 = *it;
            point p2 = *jt;

            if(p2.x == p1.x || p2.y == p1.y){
                continue;
            }

            point p3(p1.x,p2.y);
            point p4(p2.x,p1.y);

            if(s.find(p3) != s.end() && s.find(p4) != s.end()){
                ans += 1;
            }
        }
    }
    return ans/2;
}

int main()
{
    int n;
    cin>>n;

    int x,y;
    vector<point> points;
    for(int i = 0 ; i < n ; i++){
        cin>>x>>y;
        point p(x,y);
        points.push_back(p);
    }

    cout<<countRectangles(points)<<endl;
    return 0;
}
