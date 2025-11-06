#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

stack<int> inStack;
stack<int> outStack;

void prepareOutStack() {
    while(inStack.size()) {
        outStack.push(inStack.top());
        inStack.pop();
    }
}
void enqueue(int val) {
    inStack.push(val);
}
void dequeue() {
    if (outStack.empty()) {
        prepareOutStack();
    }
    outStack.pop();
}
int getval() {
    if (outStack.empty()) {
        prepareOutStack();
    }
    return outStack.top();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nqueries = 0;
    cin >> nqueries;
    vector<vector<int>> queries;
    for (int idx = 0; idx < nqueries; ++idx) {
        int act = 0, val = 0;
        cin >> act;
        if (act == 1)
            cin >> val;
        queries.push_back({act, val});
    }
    for (auto &q : queries) {
        if (q[0] == 1) {
            enqueue(q[1]);
        } else if (q[0] == 2) {
            dequeue();
        } else if (q[0] == 3) {
            cout << getval() << "\n";
        }
    }
    return 0;
}

