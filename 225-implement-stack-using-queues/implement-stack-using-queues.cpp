class MyStack {
public:
    int n;
    queue<int> q1, q2;
    MyStack() {
        n = 0;
    }
    
    void push(int x) {
        q1.push(x);
        n++;
    }
    
    int pop() {
        if(n==0){
            return -1;
        }
        for(int i=0; i<n-1; i++){
            int f = q1.front();
            q1.pop();
            q2.push(f);
        }
        int popped = q1.front();
        q1.pop();
        for(int i=0; i<n-1; i++){
            q1.push(q2.front());
            q2.pop();
        }
        n--;
        return popped;
    }
    
    int top() {
        int t = -1;
        for(int i=0; i<n; i++){
            t = q1.front();
            q1.pop();
            q2.push(t);
        }
        for(int i=0; i<n; i++){
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
        return t;
    }
    
    bool empty() {
        return n==0;
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