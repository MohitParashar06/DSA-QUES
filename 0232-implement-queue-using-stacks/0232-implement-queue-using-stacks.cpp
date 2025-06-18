class MyQueue {
public:
    stack<int> que1;
    stack<int> que2;
    MyQueue() {}
    void push(int x) {
        while(!que1.empty()){
            que2.push(que1.top());
            que1.pop();
        }
        que2.push(x);
        while(!que2.empty()){
            que1.push(que2.top());
            que2.pop();
        }
    }
    int pop() {
        int val = que1.top();
        que1.pop();
        return val;
    }
    int peek() {
        return que1.top();
    }
    bool empty() {
        return que1.empty();
    }
};