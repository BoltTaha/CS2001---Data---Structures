#include <iostream>
#include <queue>
using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        string curr = q.front();
        cout << curr << " ";
        q.pop();

        q.push(curr + "0");
        q.push(curr + "1");
    }
}

int main() {
    int n = 5;
    generateBinaryNumbers(n);
    return 0;
}
