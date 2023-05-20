/* Philosophers.h
Author: Andrew Bergman
3/21/23
Operating Systems

This file defines several objects used for the dining philosophers problem.

*/
#include <vector>
#include <iostream>
//#include <chrono>
#include <windows.h> // for Sleep
#include <mutex>

namespace Philosophers
{
    const int NUMBERPHILOSOPHERS = 5;
    const int SIMULATIONTIME = 10; // simulation time in seconds.
    std::mutex* chopsticks[5];

    void initialize()
    {
        for (int i = 0; i < 5; i++)
        {
            std::mutex* a = new std::mutex;
            chopsticks[i] = a;
        }
    }

    void teardown()
    {
        for (int i = 0; i < 5; i++)
        {
            delete chopsticks[i];
        }
    }
    // This will simulate a philosopher eating and thinking.
    // To prevent a deadlock ensure that chopstickOne < chopstickTwo
    void simulate(int philosopherNumber, int chopstickOne, int chopstickTwo) 
    {
        int aggregate = 0;
        int sleepTime = 1000;
        int eatTime = 1000;
        while(aggregate < SIMULATIONTIME*1000)
        {
            
            aggregate += sleepTime*2; // we sleep twice in the simulation
            aggregate += eatTime;
            if (aggregate < SIMULATIONTIME*1000)
            {
                std::cout << "Philosopher " << philosopherNumber << " thinking for " << sleepTime/1000 << " seconds.\n";
                Sleep(sleepTime);
                std::cout << "Philosopher " << philosopherNumber << " done thinking, now eating.\n";
                chopsticks[chopstickOne]->lock(); // pick up chopstick one
                std::cout << "Philosopher " << philosopherNumber << " picked up his right hand chopstick\n";
                Sleep(sleepTime); // to ensure deadlock if one is possible, add a delay between picking up different chopsticks
                chopsticks[chopstickTwo]->lock(); // pick up chopstick two
                std::cout << "Philosopher " << philosopherNumber << " picked up his left hand chopstick\n";
                std::cout << "Philosopher " << philosopherNumber << " eating for " << eatTime/1000 << " seconds.\n";
                Sleep(eatTime);
                std::cout << "Philosopher " << philosopherNumber << " done eating, now thinking.\n";
                chopsticks[chopstickOne]->unlock();
                chopsticks[chopstickTwo]->unlock(); 
            }
        }
    }

};

