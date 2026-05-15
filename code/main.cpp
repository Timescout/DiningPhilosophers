// main.cpp
// Dining Philosophers Problem
// Author: Andrew Bergman
// 3/21/23 updated 5/11/26
// Operating systems class, later personal project.
//
// Program entry point.



#include "Philosopher.h"



int main()
{
    // Create a simulation with 5 philosophers that will run for a minute
    // and time out after two minutes if there is a deadlock. Then run
    // it with no deadlock, and again with a deadlock.
    using namespace Philosophers;
    std::cout << "Start no deadlock simulation\n\n";
    PhilosopherSimulation simulation(5, 60, 120);
    simulation.simulateNoDeadlock();
    std::cout << "\nEnd simulation.\nStart deadlock simulation.\n\n";
    simulation.simulateDeadlock();
    std::cout << "\nEnd simulation.\n";
    return 0;
}