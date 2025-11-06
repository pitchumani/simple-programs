class Solution {
public:

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int N = parent.size();
        vector<vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            if (parent[i] == -1) continue;
            adj[parent[i]].push_back(i);
        }
        string dfsString;
        vector<int> sstart(N), ssize(N);

        function<void(int)> findDfsString = [&](int n) {
            int pos = dfsString.size();
            for (auto child : adj[n]) {
                findDfsString(child);
            }
            dfsString.push_back(s[n]);
            sstart[n] = pos;
            ssize[n] = dfsString.size() - pos;
        };
        // find dfs string for root node
        findDfsString(0);
        auto isPalindrome = [&](int st, int len) -> bool {
            int left = st, right = st + len - 1;
            while (left < right) {
                if (dfsString[left] != dfsString[right]) {
                    return false;
                }
                ++left;
                --right;
            }
            return true;
        };
        //cout << "input: " << s << "\n";
        //cout << "dfs string: " << dfsString << "\n";
        vector<bool> palindromeArray(N, false);        
        for (int n = 0; n < N; ++n) {
            //cout << "string " << string(dfsString.begin()+sstart[n], dfsString.begin()+sstart[n]+ssize[n]) << "\n";
            palindromeArray[n] = isPalindrome(sstart[n], ssize[n]);
        }
        return palindromeArray;
    }
};

