#include<iostream>
#include<gtest/gtest.h>
extern int longestSubstring(const std::string& str);

TEST(longestSubstringTest, test1) {
    // longest substring in "hello world" is " world"
    int res = longestSubstring("hello world");
    EXPECT_TRUE(res == 6) << "actual: " << res;
}

TEST(longestSubstringTest, test2) {
    // longest substring in "abcdacbabcdef" is "abcdef"
    int res = longestSubstring("abcdacbabcdef");
    EXPECT_TRUE(res == 6) << "actual: " << res;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Running longestSubstring tests" << std::endl;
    int retval = RUN_ALL_TESTS();
    return retval;
}

