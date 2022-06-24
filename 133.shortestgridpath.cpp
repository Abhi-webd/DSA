class node{
    public:
    int x;
    int y;
    int dist;
    node(int x,int y , int dist){
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

class compare{
    public:
    bool operator()(const node &a , const node &b){
        return a.dist <= b.dist;
    }
};

int shortestPath(vector<vector<int>> grid){
    int m = grid.size();
    int n = grid[0].size();

    int i = 0 ;
    int j = 0;
    
    vector<vector<int>> dist(m+1,vector<int>(n+1,INT_MAX));

    dist[i][j] = grid[0][0];
    set<node,compare> s;
    s.insert(node(0,0,dist[0][0]));

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    while(!s.empty()){
        auto it = s.begin();
        int cx = it->x;
        int cy = it->y;
        int cd = it->dist;
        s.erase(it);

        for(int k = 0 ; k < 4 ; k++){
            int nx = cx + dx[k];
            int ny = cy + dy[k];

            if(nx >=0 && ny >=0 && nx < m && ny < n && cd+grid[nx][ny] < dist[nx][ny]){
                node temp(nx,ny,dist[nx][ny]);
                if(s.find(temp) != s.end()){
                    s.erase(s.find(temp));
                }

                int nd  = grid[nx][ny]+cd;
                dist[nx][ny] = cd;
                s.insert(node(nx,ny,cd));
            }
        }
    }


}
