#include<string>
#include<iostream>
using namespace std;
   
string convert_opt(string s, int numRows) {
    if ((numRows == 1) || (numRows > s.size())) return s;
    vector<string> rowStrings(numRows);
    int rid = 0;
    bool inreverse = false;
    for (auto c : s) {
        rowStrings[rid] += c;
        if ((rid == 0) || (rid == numRows - 1)) {
            inreverse = !inreverse;
        }
        rid += inreverse ? 1 : -1;
    }
    string res;
    res.reserve(s.size());
    for (auto rs : rowStrings) {
        res += rs;
    }
    return res;
}
string convert(string s, int numRows) {
    if ((numRows == 1) || (numRows > s.size())) return s;
    vector<string> rowStrings(numRows);
    int rid = 0;
    bool inreverse = false;
    for (auto c : s) {
        //cout << "adding " << c << " to row " << rid << "\n";
        rowStrings[rid] += c;
        if (inreverse)
            --rid;
        else
            ++rid;
        if ((inreverse == false) && (rid == numRows)) {
            rid -= 2;
            inreverse = true;
        }
        if (inreverse && (rid == 0)) {
            inreverse = false;
        }
    }
    string res;
    res.reserve(s.size());
    for (auto rs : rowStrings) {
        //cout << rs << "\n";
        res += rs;
    }
    return res;
}

int main () {
    std::string expstr("PAHNAPLSIIGYIR");
    std::string str = convert("PAYPALISHIRING", 3);
    if (str != expstr) cout << "FAIL!  ";
    else cout << "PASS!!  ";
    std::cout << "Expected: " << expstr << ". Got " << str << "\n";
    std::string str1 = convert_opt("PAYPALISHIRING", 3);
    if (str1 != expstr) cout << "FAIL!  ";
    else cout << "PASS!!  ";
    std::cout << "Expected: " << expstr << ". Got " << str1 << "\n";
    return 0;
}
