// PhilosopherTest.h
// Dining Philosophers problem
// Author: Andrew Bergman
// 5/13/26
// Operating Systems class, later personal project.
//
// Tests for PhilosopherSimulation class.



#include <gtest/gtest.h>

#include "Philosopher.h"



TEST(PhilosopherSimulationUnitTest, DefaultConstructor_Works) 
{
    Philosophers::PhilosopherSimulation testSim;

    EXPECT_EQ(testSim.getNumberPhilosophers(), Philosophers::PhilosopherSimulation::DEFAULTnUMBERpHILOSOPHERS);
    EXPECT_EQ(testSim.getSimulationTime(), Philosophers::PhilosopherSimulation::DEFAULTsIMULATIONtIME);
    EXPECT_EQ(testSim.getSimulationTimeoutTime(), Philosophers::PhilosopherSimulation::DEFAULTsIMULATIONtIMEOUTtIME);
}

TEST(PhilosopherSimulationUnitTest, ArgumentedConstructor_2Philosophers0MinTime1Maxtime_Works)
{
    int numTestPhilosophers = 2, minTime = 0, maxTime = 1;
    Philosophers::PhilosopherSimulation testSim(numTestPhilosophers, minTime, maxTime);
    
    EXPECT_EQ(testSim.getNumberPhilosophers(), numTestPhilosophers);
    EXPECT_EQ(testSim.getSimulationTime(), minTime);
    EXPECT_EQ(testSim.getSimulationTimeoutTime(), maxTime);
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

TEST(PhilosopherSimulationUnitTest, CallSimulationNoDeadlock_Exits)
{
    Philosophers::PhilosopherSimulation testSim(5, 5, 6);

    EXPECT_EXIT((testSim.simulateNoDeadlock(), exit(0)), testing::ExitedWithCode(0), ".*");
    // Source: https://stackoverflow.com/questions/47583352/how-to-catch-segmentation-fault-with-google-test
    // acssesed 5/14/26
}

TEST(PhilosopherSimulationUnitTest, CallSimulationDeadlock_Exits)
{
    Philosophers::PhilosopherSimulation testSim(5, 5, 6);

    EXPECT_EXIT((testSim.simulateDeadlock(), exit(0)), testing::ExitedWithCode(0), ".*");
    // Source: https://stackoverflow.com/questions/47583352/how-to-catch-segmentation-fault-with-google-test
    // acssesed 5/14/26
}