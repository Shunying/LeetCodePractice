#include <vector>
#include <iostream>
#include <stack>

using namespace std;


class MinStack {
public:
    stack<int> A;  // the major stack
    stack<int> B;  // for min record

    MinStack() {
    }

    void push(int val) {
        A.push(val);
        if (B.empty() || val <= B.top()) {
            B.push(val);
        }
    }

    void pop() {
        int tmp = A.top();
        A.pop();
        if (tmp == B.top()) {
            B.pop();
        }
    }

    int top() {
        return A.top();
    }

    int getMin() {
        return B.top();
    }
};


int main() {
    MinStack* obj = new MinStack();
    obj->push(0);
    obj->push(1);
    obj->push(0);

    cout << obj->getMin() << endl;

    obj->pop();

    //cout << obj->top() << endl;

    cout << obj->getMin() << endl;

    return 0;
}