#include <iostream>
#include <gtest/gtest.h>

extern int nAnagrams(std::vector<std::string> stringsList, std::string word);

// tests for nAanagram

TEST(nAnagramTest, test1) {
    std::vector<std::string> strings;
    strings.emplace_back("listen");
    strings.emplace_back("listener");
    strings.emplace_back("silent");
    strings.emplace_back("silents");
    strings.emplace_back("enlist");
    strings.emplace_back("list");
    strings.emplace_back("listened");
    // sintel has 3 anagrams in the list strings
    int n_anagrams = nAnagrams(strings, "sintel");
    EXPECT_TRUE(n_anagrams == 3) << "actual: " << n_anagrams;
}

TEST(nAnagramTest, test2) {
    std::vector<std::string> strings;
    strings.emplace_back("listen");
    strings.emplace_back("listener");
    strings.emplace_back("silent");
    strings.emplace_back("silents");
    strings.emplace_back("enlist");
    strings.emplace_back("list");
    strings.emplace_back("listened");
    strings.emplace_back("sintel");
    // sintel has 3 anagrams in the list strings
    // the exact same word sintel should be ignored
    int n_anagrams = nAnagrams(strings, "sintel");
    EXPECT_TRUE(n_anagrams == 3) << "actual: " << n_anagrams;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Running nAnagrams tests" << std::endl;
    int retval = RUN_ALL_TESTS();
    return retval;
}

