#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

stack<int> mainstack;
stack<int> sparestack;
bool isMainStack = true;
void enqueue(int val) {
    if (isMainStack) {
        mainstack.push(val);
    } else {
        while(sparestack.size()) {
            mainstack.push(sparestack.top());
            sparestack.pop();
        }
        mainstack.push(val);
        isMainStack = true;
    }
}
void dequeue() {
    if (isMainStack == false)
        sparestack.pop();
    else {
        while(mainstack.size()) {
            sparestack.push(mainstack.top());
            mainstack.pop();
        }
        sparestack.pop();
        isMainStack = false;
    }
}
int getval() {
    if (isMainStack == false)
        return sparestack.top();
    else {
        while (mainstack.size()) {
            sparestack.push(mainstack.top());
            mainstack.pop();
        }
        int val = sparestack.top();
        isMainStack = false;
        return val;
    }
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

