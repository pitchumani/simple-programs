#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(vector<string> words) {
    vector<string> tested;
    for (int i = 0; i < words.size(); ++i) {
        const string &curr = words[i];
        for (const string& prev : tested) {
            if (curr.rfind(prev, 0) == 0) {
                cout << "BAD SET\n" << curr << "\n";
                return;
            }
            if (prev.rfind(curr, 0) == 0) {
                cout << "BAD SET\n" << curr << "\n";
                return;
            }
        }
        //cout << "added " << curr << " to the tested set\n";
        tested.push_back(curr);
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

