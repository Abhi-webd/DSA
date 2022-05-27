#include <bits/stdc++.h>
using namespace std;

vector<string> method1(string s, char delm){
    vector<string> ans;
    stringstream ss(s);

    string token;
    while(getline(ss,token,delm)){
        ans.push_back(token);
    }
    return ans;

}

int main()
{
    // string input;
    // getline(cin,input);
    // auto p = method1(input,' ');
    // for( auto i : p){
    //     cout<<i<<",";
    // }

    // for  char array we use strtok
    char input[1000];
    cin.getline(input,1000);

    char* token = strtok(input," ");
    while(token != NULL){
        cout<<token<<endl;
        token = strtok(NULL," ");
    }
    return 0;
}
