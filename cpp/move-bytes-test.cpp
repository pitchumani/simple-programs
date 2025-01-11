#include <iostream>
#include <gtest/gtest.h>

extern void moveBytes(char * src, char * dest, int number);

// tests for moveBytes

TEST(moveBytesTest, Test1) {
    char arr1[] = "abcde";
    char arr2[] = "*****";
    moveBytes(arr1, arr2, 5);
    EXPECT_EQ(0, strcmp(arr2, "abcde"));
}

TEST(moveBytesTest, Test2) {
    char *arr1 = nullptr;
    char *arr2 = nullptr;
    moveBytes(arr1, arr2, 12);
    EXPECT_TRUE(arr1 == nullptr && arr2 == nullptr);
}

TEST(moveBytesTest, Test3) {
    char *arr1 = "hello";
    char *arr2 = "world";
    moveBytes(arr1, arr2, 0);
    EXPECT_TRUE(strcmp(arr1, "hello") == 0 &&
                strcmp(arr2, "world") == 0);
}

TEST(moveBytesTest, Test4) {
    char arr1[] = "test string";
    char arr2[] = "hello world";
    moveBytes(arr2, arr1, 5);
    EXPECT_TRUE(strcmp(arr1, "hellostring") == 0);
}

TEST(moveBytesTest, Test5) {
    char arr1[] = "hello world";
    moveBytes(arr1, arr1+6, 5);
    EXPECT_TRUE(strcmp(arr1, "hello hello") == 0);
}

TEST(moveBytesTest, Test6) {
    char arr1[] = "0123456789";
    moveBytes(arr1+4, arr1, 6);
    // failure message is added by << after EXPECT_TRUE
    EXPECT_TRUE(strcmp(arr1, "4567896789") == 0) << "actual: " << arr1;
}

TEST(moveBytesTest, Test7) {
    char arr1[] = "0123456789";
    moveBytes(arr1, arr1+4, 6);
    EXPECT_TRUE(strcmp(arr1, "01230123456") == 0) << "actual: " << arr1;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Running moveBytes tests" << std::endl;
    int retval = RUN_ALL_TESTS();
    return retval;
}
