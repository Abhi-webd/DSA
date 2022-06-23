#include <bits/stdc++.h>
using namespace std;
#define MAX 26
int anagram_substring(string str, int length){
   int count = 0;
   map<vector<int>, int> mp_vec;
   for (int i=0; i<length; i++){
      vector<int> vec(MAX, 0);
      for (int j=i; j<length; j++){
         char c = str[j];
         vec[c-'a']++;
         mp_vec[vec]++;
      }
   }
   for (auto it = mp_vec.begin(); it != mp_vec.end(); it++){
      int last = it->second;
      count += ((last) * (last-1))/2;
   }
   return count;
}
int main(){
   string str = "abba";
   int length = str.length();
   cout<<"Count of total anagram substrings are: "<<anagram_substring(str, length) << endl;
   return 0;
}
