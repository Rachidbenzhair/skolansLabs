#include<iostream>
#include<stack>

using namespace std;

struct Queue {
    stack<int> stack1, stack2;

    void enQueue(int x)
    {

        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }

        stack1.push(x);

        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
    }

    int deQueue()
    {
        if (stack1.empty()) {
            cout << "Q is Empty";
            exit(0);
        }

        int x = stack1.top();
        stack1.pop();
        return x;
    }
};

//int main()
//{
//    Queue q;
//    q.enQueue(1);
//    q.enQueue(2);
//    q.enQueue(3);
//
//    cout << q.deQueue() << '\n';
//    cout << q.deQueue() << '\n';
//    cout << q.deQueue() << '\n';
//
//    return 0;
//}