vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		  //  sort(s.begin(),s.end());
		    
		    int n = s.length();
		    for(int i = 1 ;  i < (1 << n) ; i++){
		        string t = "";
		        for(int j = 0 ; j < n ; j++){
		            if(i & ( 1 << j)){
		                t += s[j];
		            }
		        }
		        ans.push_back(t);
		    }
		    sort(ans.begin(),ans.end());
	
           return ans;
		}
