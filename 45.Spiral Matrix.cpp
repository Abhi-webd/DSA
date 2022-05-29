class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        int is = 0;
        int js = 0;
        int ie = a.size();
        int je = a[0].size();
        int i = 0 ;
        int j = 0;
        cout<<ie<<" "<<je<<endl;
        vector<int> ans;
        while(is < ie && js < je){
            while(i == is && j <= je-1){
                ans.push_back(a[i][j]);
                cout<<1<<" "<<i<<" "<<j<<endl;
                j++;
            }
            is++;
            i++;
            j--;
            while(i < ie && j == je-1 ){
                ans.push_back(a[i][j]);
                 cout<<2<<" "<<i<<" "<<j<<endl;
                i++;
            }
            je--;
            j--;
            i--;

            while( i == ie-1 && j >=js){
                ans.push_back(a[i][j]);
                 cout<<3<<" "<<i<<" "<<j<<endl;
                j--;
            }
            ie--;
            i--;
            cout<<3<<" "<<i<<" "<<j<<endl;
            while( i >= is && j == js){
                ans.push_back(a[i][j]);
                 cout<<4<<" "<<i<<" "<<j<<endl;
                i--;
            }
            js++;
            j++;
            
        }
        return ans;
    }
};
