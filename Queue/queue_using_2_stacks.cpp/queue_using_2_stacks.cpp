#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    void enqueue(int val) {
        s1.push(val);
    }

    void dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is Empty\n";
                return;
            }
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }

    void display() {
        if (s2.empty() && s1.empty()) {
            cout << "Queue is Empty\n";
            return;
        }

        stack<int> temp = s2;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        stack<int> temp2 = s1;
        while (!temp2.empty()) {
            cout << temp2.top() << " ";
            temp2.pop();
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();
    return 0;
}
