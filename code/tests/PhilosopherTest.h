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

TEST(PhilosopherSimulationUnitTest, SetNumberPhilosophers_0_Throws) 
{
    Philosophers::PhilosopherSimulation testSim;

    EXPECT_THROW(testSim.setNumberPhilosophers(0), std::out_of_range);
}

TEST(PhilosopherSimulationUnitTest, SetNumberPhilosophers_2_DoesNotThrow)
{
    Philosophers::PhilosopherSimulation testSim;

    EXPECT_NO_THROW(testSim.setNumberPhilosophers(2));
}

TEST(PhilosopherSimulationUnitTest, SetSimulationTimeFrame_SameValue_DoesNotThrow)
{
    Philosophers::PhilosopherSimulation testSim;

    EXPECT_NO_THROW(testSim.setSimulationTimeFrame(0, 0));
}

TEST(PhilosopherSimulationUnitTest, SetSimulationTimeFrame_SmallerTimeoutTime_Throws)
{
    Philosophers::PhilosopherSimulation testSim;

    EXPECT_THROW(testSim.setSimulationTimeFrame(1, 0), std::logic_error);
}