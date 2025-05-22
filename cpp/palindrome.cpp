#include <iostream>
#include <string>

// check if the string is a palindrome
bool isPalindrome(std::string s) {
    int left = 0;
    int right = s.size() - 1;
    while(left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}

// check if the string is a palindrome within the left and right indices
bool isPalindrome(std::string s, int left, int right) {
    while(left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}

// find the index of a character in the string whose removal
// makes the string palindrome. Return -1 otherwise.
int indexPalindrome(std::string s) {
    // TODO:
    return -1;
}
    
#ifndef __UNITTEST__
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
        exit(1);
    }
    auto res = isPalindrome(argv[1]);
    if (res)
        std::cout << argv[1] << " is a palindrome.\n";
    else
        std::cout << argv[1] << " is not a palindrome.\n";
    return 0;
}
#endif  // __UNITTEST__

