class Solution {
public:

    vector<bool> findAnswer(vector<int>& parent, string s) {
        int N = parent.size();
        vector<vector<int>> adj(N);
        for (int i = 0; i < N; ++i) {
            if (parent[i] == -1) continue;
            adj[parent[i]].push_back(i);
        }
        vector<string> dfsStrings(N);
        vector<bool> visited(N, false);

        function<string(int)> dfsString = [&](int n) {
            if (visited[n]) return dfsStrings[n];
            string str;
            for (auto child : adj[n]) {
                str +=  dfsString(child);
            }
            str.push_back(s[n]);
            dfsStrings[n] = str;
            visited[n] = true;
            return str;
        };
        auto isPalindrome = [&](string str) -> bool {
            int left = 0, right = str.size() - 1;
            while (left < right) {
                if (str[left] != str[right]) {
                    return false;
                }
                ++left;
                --right;
            }
            return true;
        };
        vector<bool> palindromeArray(N, false);        
        for (int n = 0; n < N; ++n) {
            string str = dfsString(n);
            palindromeArray[n] = isPalindrome(str);
        }
        return palindromeArray;
    }
};

