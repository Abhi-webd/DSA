void insertSorted(int x, stack<int> &s){
    if(s.empty() || x > s.top()){
        s.push(x);
        return;
    }
    int y = s.top();
    s.pop();
    insertSorted(x,s);
    s.push(y);
}

void SortedStack :: sort()
{
   //Your code here
   if(!s.empty()){
       int x = s.top();
       s.pop();
       sort();
       insertSorted(x,s);
   }
