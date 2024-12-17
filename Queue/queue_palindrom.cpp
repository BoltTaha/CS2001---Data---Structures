#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool isPalindrome(queue<int>& q) {
    stack<int> s;
    queue<int> originalQueue = q;
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty()) {
        if (s.top() != originalQueue.front()) {
            return false;
        }
        s.pop();
        originalQueue.pop();
    }
    return true;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(2);
    q.push(1);

    if (isPalindrome(q)) {
        cout << "Queue is Palindrome\n";
    } else {
        cout << "Queue is not Palindrome\n";
    }
    return 0;
}
