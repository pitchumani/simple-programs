#include<iostream>
#include<gtest/gtest.h>

#include "smartptr.h"

TEST(sharedptrTest, test1) {
    // restricted to create object directly
    // sharedptr sp(0);
    int val = 100;
    sharedptr<int> sp1 = sharedptr<int>::make();
    int count = sp1.count();
    EXPECT_EQ(count, 1) << "actual: " << count;

    // create a block scope check ref count update
    // by destructor
    {
        sharedptr<int> sp2 = sp1;
        count = sp2.count();
        EXPECT_EQ(count, 2) << "actual: " << count;
        count = sp1.count();
        EXPECT_EQ(count, 2) << "actual: " << count;
    }
    
    // after the above block scope the ref count must
    // have been reduced as sp2 scope ended
    count = sp1.count();
    EXPECT_EQ(count, 1) << "actual: " << count;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "Running longestSubstring tests" << std::endl;
    int retval = RUN_ALL_TESTS();
    return retval;
}

