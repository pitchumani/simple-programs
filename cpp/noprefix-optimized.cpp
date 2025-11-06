#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */
     struct TNode {
        TNode *children[10]= {nullptr};
        bool is_end;
    };
class Trie {

    TNode *root = nullptr;
public:
    Trie(){
        root = new TNode();
    };
    bool insert(string s) {
        TNode *node = root;
        for (char c : s) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TNode();
            }
            node = node->children[idx];
            if (node->is_end)
                return true;
        }
        for (int i = 0; i < 10; ++i) {
            if (node->children[i])
                return true;
        }
        node->is_end = true;
        return false;
    }
};
void noPrefix(vector<string> words) {
    Trie trie;
    for (auto &word : words) {
        if (trie.insert(word)) {
            cout << "BAD SET\n";
            cout << word << "\n";
            return;
        }
    }
    cout << "GOOD SET\n";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

