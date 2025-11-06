// Leetcode problem 3327
// Find if the string formed by dfs traversal is a palindrome or not.
// given: list of parents and string - s[i] is assigned to node i

class Solution {
public:

    string dfsStr(string &s, vector<vector<int>> &adj, int node) {
        string str;
        for (auto a : adj[node]) {
            string astr = dfsStr(s, adj, a);
            str += astr;
        }
        str.push_back(s[node]);
        //cout << "For node " << node << " got string " << str << endl;
        return str;
    }
    vector<bool> findAnswer(vector<int>& parent, string s) {
        vector<vector<int>> adj(parent.size());
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == -1) continue;
            adj[parent[i]].push_back(i);
        }
        vector<bool> palindromeArray(parent.size(), false);
        auto isPalindrome = [](string str) -> bool {
            int len = str.size();
            int left = len / 2;
            int right = len / 2;
            if (len & 1) {
                left -= 1;
                right += 1;
            } else {
                left -= 1;
            }
            while ((left >= 0) && (right <= len)) {
                if (str[left] != str[right]) return false;
                --left;
                ++right;
            }
            return true;
        };
        /*
        cout << "parents list: ";
        for (auto p : parent) cout << p << " ";
        cout << "\n";
        cout << "adjacency list: ";
        for (int n = 0; n < adj.size(); ++n) {
            cout << " adj[" << n << "]: ";
            for (auto a : adj[n]) {
                cout << a << " ";
            }
            cout << "\n";
        }
        cout << "input: " << s << "\n";
        string dfsString = dfsStr(s, adj, 0);
        cout << "dfsString: " << dfsString << "\n";
        */
        for (int n = 0; n < parent.size(); ++n) {
            string str = dfsStr(s, adj, n);
            //cout << "string at node " << n << " is: " << str << "\n";
            palindromeArray[n] = isPalindrome(str);
        }
        return palindromeArray;
    }
};

// optimizations:
// - avoid dfsstring formation for every node
// - - preorder dfsstring is enough, each node's preorder-dfs string will be
// the substring
// - - then palindrome check can be optimized to check only with left and right
// index to the preorder-dfs string


int main (int argc, char *argv[]) {
}
 
