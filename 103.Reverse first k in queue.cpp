// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    queue<int> t1;
    stack<int> s;
    
    int temp = k;
    while(k){
        s.push(q.front());
        q.pop();
        k--;
    }
    
    int n = q.size();
    while(n){
        t1.push(q.front());
        q.pop();
        n--;
    }
    
    while(temp){
        q.push(s.top());
        s.pop();
        temp--;
    }
    temp = t1.size();
    while(temp){
        q.push(t1.front());
        t1.pop();
        temp--;
    }
    return q;
}
