/*
  You have just written down a string of parentheses,
  and now you want to check whether it is well-formed
  string. You must determine the minimum number of
  insertions to turn your string into a well-formed
  one. No deletions are allowed.

  A string of parentheses is well-formed if it meets
  the following requirements:
  - An empty string is well-formed
  - If S is well-formed string, then (S) is well-formed
  string.
  - If S1 and S2 are well-formed strings, their concatenation,
  S1S2 is also a well-formed string.

  Input: string containing only "(" and ")"
  Output: Print the minimum number of insertions to turn
  your string into a well-formed string.

  e.g. #1
  Input: ()(()
  Output: 1
*/
#include <iostream>
#include <stack>
#include <string>
int wellFormString(std::string str) {
	std::stack<char> pstack;
	int nInserts = 0;
	for (auto c : str) {
		if (c == '(') {
			pstack.push(c);
		} else if (c == ')') {
			if (pstack.empty()) {
				nInserts += 1;
			} else {
				pstack.pop();
			}
		}
	}
	nInserts += pstack.size();
	return nInserts;
}

int main() {
	std::string str1("()(()");
	std::cout << "Number of inserts to well-form '" << str1 <<
		"': " << wellFormString(str1) << std::endl;
	std::string str2("()()");
	std::cout << "Number of inserts to well-form '" << str2 <<
		"': " << wellFormString(str2) << std::endl;
	return 0;
}
