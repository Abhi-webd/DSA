class MyStack {
public:
    queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int a = q1.size()-1;
        while(a){
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
            a--;
        }
    }
    
    int pop() {
        if(q1.size() == 0){
            return -1;
        }
        int temp = q1.front();
        q1.pop();
        return temp;
    }
    
    int top() {
        if(q1.size() == 0){
            return -1;
        }
        int temp = q1.front();
        return temp;
    }
    
    bool empty() {
        if(q1.size() == 0){
            return true;
        }
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
