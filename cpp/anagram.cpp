/*
  For the possible anagrams.
*/

#include <vector>
#include <string>
#include <algorithm>

int nAnagrams(std::vector<std::string> stringsList, std::string word) {
    std::string sorted_word(word);
    std::sort(sorted_word.begin(), sorted_word.end());
    int n_anagrams = 0;
    for (auto &str : stringsList) {
        std::string sorted_str(str);
        std::sort(sorted_str.begin(), sorted_str.end());
        if (sorted_str == sorted_word) {
            ++n_anagrams;
        }
    }
    return n_anagrams;
}

