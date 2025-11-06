/*
  You are given  integers in sorted order. Also, you are given  queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.
Lower bound is a function that can be used with a sorted vector. Learn how to use lower bound to solve this problem by clicking here.
Input Format
The first line of the input contains the number of integers . The next line contains  integers in sorted order. The next line contains , the number of queries. Then  lines follow each containing a single integer .
Note: If the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    vector<int> numbers;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        numbers.push_back(j);
    }
    auto printv = [](const vector<int> V) {
        for (auto &i : V)
            cerr << i << " ";
        cerr << "\n";
    };
    printv(numbers);
    cerr << std::endl;    
    // get n queries
    cin >> n;
    vector<int> queries;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        queries.push_back(j);
    }
    printv(queries);
    for (auto &i : queries) {
        auto itr = std::lower_bound(numbers.begin(), numbers.end(), i);
        if (itr != numbers.end()) {
			if (*itr == i) {
				cout << "Yes " << itr - numbers.begin() + 1 << std::endl;
			} else {
				cout << "No " << itr - numbers.begin() + 1 << std::endl;
			}
        }
    }    
    return 0;
}

