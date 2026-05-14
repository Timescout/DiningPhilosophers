// gtest.cpp
// Dining Philosophers problem
// Andrew Bergman
// 5/13/26
//
// This file is the program entry point for the testing executible.

#include <gtest/gtest.h>

#include "PhilosopherTest.h"

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}