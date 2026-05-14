// PhilosopherTest.h
// Dining Philosophers problem
// Andrew Bergman
// 5/13/26
//
// Tests for PhilosopherSimulation class.

#include <gtest/gtest.h>

#include "Philosopher.h"

TEST(PhilosopherSimulationUnitTest, DefaultConstructor_Works) 
{
    EXPECT_NO_THROW(Philosophers::PhilosopherSimulation testSim);
}