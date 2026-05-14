/* Philosophers.h
Author: Andrew Bergman
3/21/23 updated 5/11/26
Operating Systems

This file defines objects used for the dining philosophers problem.

*/
#include <vector>
#include <iostream>
#include <chrono>
//#include <windows.h> // for Sleep
#include <mutex>
#include <thread>

namespace Philosophers
{
    class PhilosopherSimulation 
    {
    private:
        unsigned int numberPhilosophers_;
        unsigned int simulationTime_;
        unsigned int simulationTimeoutTime_;
        std::vector<std::mutex*> chopsticks_;

        static void simulatePhilosopher(int philosopherNumber, std::mutex chopstickOne, std::mutex chopstickTwo) 
        {}
    public:
        PhilosopherSimulation(int numberPhilosophers, int simulationTime, int simulationTimeoutTime) :
            numberPhilosophers_(numberPhilosophers),
            simulationTime_(simulationTime),
            simulationTimeoutTime_(simulationTimeoutTime),
            chopsticks_(numberPhilosophers, nullptr)
        {
            for (int i = 0; i < numberPhilosophers_; i++) {
                std::mutex* a = new std::mutex;
                chopsticks_[i] = a;
            }
        }

        PhilosopherSimulation() 
        {
            PhilosopherSimulation(5, 10, 20);
        }

        ~PhilosopherSimulation() 
        {
            for (std::vector<std::mutex*>::iterator i = chopsticks_.begin(); i != chopsticks_.end(); i++)
            {
                delete *i;
                *i = nullptr;
            }
        }

        // void simulateDeadlock() 
        //    {
        //     std::vector<std::thread> philosophers(numberPhilosophers_);
        //     for (int i = 0; i < numberPhilosophers_; i++) {
        //         philosophers.push_back(std::thread(PhilosopherSimulation::simulatePhilosopher, i, *chopsticks_[i], *chopsticks_[(i + 1) % numberPhilosophers_]));
        //     }
        //     std::this_thread::sleep_for(std::chrono::seconds(simulationTime_));
        //     for (auto i = philosophers.begin(); i != philosophers.end(); i++) 
        //{
        //         i->join();
        //         //std::terminate(*i);
        //     }
        // }

        void simulateNoDeadlock() 
        {}
    };
/*
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
                //Sleep(sleepTime);
                std::cout << "Philosopher " << philosopherNumber << " done thinking, now eating.\n";
                chopsticks[chopstickOne]->lock(); // pick up chopstick one
                std::cout << "Philosopher " << philosopherNumber << " picked up his right hand chopstick\n";
                //Sleep(sleepTime); // to ensure deadlock if one is possible, add a delay between picking up different chopsticks
                chopsticks[chopstickTwo]->lock(); // pick up chopstick two
                std::cout << "Philosopher " << philosopherNumber << " picked up his left hand chopstick\n";
                std::cout << "Philosopher " << philosopherNumber << " eating for " << eatTime/1000 << " seconds.\n";
                //Sleep(eatTime);
                std::cout << "Philosopher " << philosopherNumber << " done eating, now thinking.\n";
                chopsticks[chopstickOne]->unlock();
                chopsticks[chopstickTwo]->unlock(); 
            }
        }
    }

    void simulateDeadlock()
    {
        std::thread philosophers[NUMBERPHILOSOPHERS];
        for (int i = 0; i < NUMBERPHILOSOPHERS; i++)
        {
            philosophers[i] = std::thread(simulate, i, i, (i + 1) % NUMBERPHILOSOPHERS);
        }
        for (int i = 0; i < NUMBERPHILOSOPHERS; i++)
        {
            philosophers[i].join();
        }
    }

    void simulateNoDeadlock()
    {
        initialize();
        std::thread philosophers[NUMBERPHILOSOPHERS];
        for (int i = 0; i < NUMBERPHILOSOPHERS-1; i++)
        {
            philosophers[i] = std::thread(simulate, i, i, (i + 1) % NUMBERPHILOSOPHERS); // each of the first four philosophers can be set up in this way
        }
        philosophers[NUMBERPHILOSOPHERS-1] = std::thread(simulate, NUMBERPHILOSOPHERS-1, 0, NUMBERPHILOSOPHERS-1); // but the fifth must be special
        for (int i = 0; i < NUMBERPHILOSOPHERS; i++)
        {
            philosophers[i].join();
        }
        
        teardown();
    }
        */
};

