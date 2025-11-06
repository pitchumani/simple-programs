#include <bits/stdc++.h>
using namespace std;

/* Code Chef
 * You are given a sequ of non-negative integers A1, A2, .. An.
 * There is a pawn placed on the first elelment of the sequence, ie.e at pos 1.
 * When the pawn is on the pos numbered with x, it can jump at mose Ax places
 * to the right. In other workds, if Ax > 0, the pawn can jump to any pos from
 * x+1 to x+Ax. If Ax == 0, the pawn can not move from the position numbered
 * with x at all.
 *
 * Find the max possible number of jumps using which it is possible to place
 * the pawn on the last position, i.e. the postion numbered with N, or
 * determine that it is impossible to reach it.
 */

int getNumMoves(int n, vector<int> moves) {
    // pawn can't be moved
    if (moves[0] == 0) return -1;
    int max_posibilities = -1;
    int pos = 0;
    int njumps = 0;
    while (pos < n) {
        int m = moves[pos];
        // if can't be moved, break
        if (m == 0) break;
        pos += m;
        cerr << "jumped to " << pos << " (njumps: " << njumps << ")\n";
        ++njumps;
    }
    if (pos == (n-1)) return njumps;
    return -1;
}

int main() {
	// your code goes here
	int ntests;
	cin >> ntests;
	cin.ignore();
	typedef std::pair<int, vector<int>> test_t;
	vector<test_t> tests;
	for (int i = 0; i < ntests; ++i) {
	    string line;
	    getline(cin, line);
	    int n = stoi(line);
	    getline(cin, line);
	    cerr << "moves input: " << line << "\n";
	    vector<int> moves;
	    stringstream ss(line);
	    int x = 0;
	    while(ss >> x) {
	        moves.push_back(x);
	    };
	    tests.emplace_back(n, moves);
	}
	for (auto &t : tests) {
	    cerr << "n: " << t.first << " moves: ";
        for (auto &m : t.second) cerr << " " << m;
        cerr << "\n";
	    cout << getNumMoves(t.first, t.second) << "\n";
	}
    return 0;
}

