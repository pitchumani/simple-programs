#include<iostream>
#include<string>
#include<list>
#include<algorithm>

int longestSubstring(const std::string& str) {
    int maxLengthMatched = 0;
    int rightIndex = 0;
    std::list<char> char_set;
    for (char c : str) {
        auto it = std::find(char_set.begin(), char_set.end(), c);
        if (it != char_set.end()) {
            char_set.erase(char_set.begin(), std::next(it));
        }
        char_set.push_back(c);
        rightIndex++;
        int currMatch = char_set.size();
        if (currMatch > maxLengthMatched)
            maxLengthMatched = currMatch;
    }
    return maxLengthMatched;
}

#ifndef __UNITTEST__
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
        exit(1);
    }
    int len = longestSubstring(std::string(argv[1]));
    std::cout << len << std::endl;
    return 0;
}
#endif  // __UNITTEST__

