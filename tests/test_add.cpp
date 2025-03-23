#include <gtest/gtest.h>
#include "../include/add.h"

// Test for add() - Should pass after changes
TEST(AddTest, AddFunction) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(-1, 1), 0);
}

