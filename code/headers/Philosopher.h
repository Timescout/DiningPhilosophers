// Philosophers.h
// Author: Andrew Bergman
// 3/21/23 updated 5/11/26
// Operating Systems class, later personal project.
//
// This file defines the simulation class.

#include <vector>
#include <iostream>
#include <chrono>
#include <mutex>
#include <thread>
#include <stdexcept>

namespace Philosophers
{
    /// @brief The Class that handles the simulation. 
    class PhilosopherSimulation 
    {
    private:
        ///// Member variables /////

        /// @brief The number of Philosophers that will be involved in the simulation. Will be at least two.
        unsigned int numberPhilosophers_;

        /// @brief The total time that the simulation will run for when started, in seconds. Philosophers will continue to eat until this time is reached at which point no philosophers will start eating but can continue eating. Must be shorter or equal to simulation timeout time.
        unsigned int simulationTime_;

        /// @brief The amount of time after which the simulation will force quit. Must be longer or equal to simulation time.
        unsigned int simulationTimeoutTime_;

        /// @brief The vector of chopsticks. This will be as big as the number of philosophers.
        std::vector<std::mutex*> chopsticks_;



        ///// private functions. /////

        /// @brief The function that simulates a philosopher. This is run using multithreading.
        /// @param philosopherNumber The label for this philosopher. I.e "Philosopher 1, Philosopher 2, etc."
        static void simulatePhilosopher(int philosopherNumber, std::mutex chopstickOne, std::mutex chopstickTwo) 
        {}



    public:
        ///// Constructors and Deconstructors /////

        /// @brief Argumented constructor
        /// @param numberPhilosophers The number of philosophers simulated. Must be at least 2.
        /// @param simulationTime The minimum time the simulation will run for.
        /// @param simulationTimeoutTime The maximum time the simulation will run for.
        PhilosopherSimulation(unsigned int numberPhilosophers, unsigned int simulationTime, unsigned int simulationTimeoutTime) :
            chopsticks_(numberPhilosophers, nullptr)
        {
            setNumberPhilosophers(numberPhilosophers);
            setSimulationTimeFrame(simulationTime, simulationTimeoutTime);
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



        ///// Get functions /////

        unsigned int getNumberPhilosophers() { return numberPhilosophers_; }

        unsigned int getSimulationTime() { return simulationTime_; }

        unsigned int getSimulationTimeoutTime() { return simulationTimeoutTime_; }



        ///// Set functions /////

        /// @brief Set the number of philosophers
        /// @param newNumberPhilosophers Must be at least 2 as the simulation must have at least 2 philosophers.
        /// @throws std::out_of_range If newNumberPhilosophers < 2.
        void setNumberPhilosophers(unsigned int newNumberPhilosophers) 
        {
            if (newNumberPhilosophers < 2) { throw(std::out_of_range("Tried to create simulation with to few philosophers")); }
            numberPhilosophers_ = newNumberPhilosophers;
        }

        /// @brief Set the simulation times. Since we need to enforce that simulation time is shorter than timeout time, we need to set both at once.
        /// @param newSimulationTime Must be shorter or equal to than newSimulationTimeoutTime.
        /// @param newSimulationTimeoutTime Must be longer or equal to than newSimulatinTime.
        void setSimulationTimeFrame(unsigned int newSimulationTime, unsigned int newSimulationTimeoutTime)
        {
            if ( newSimulationTimeoutTime < newSimulationTime) 
            { 
                throw std::logic_error("simulation time longer than simulation timeout time");
            }
            simulationTime_ = newSimulationTime;
            simulationTimeoutTime_ = newSimulationTimeoutTime;
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

        // void simulateNoDeadlock() 
        // {
        //     // I'm using an array of threads rather than a vector for a number of reasons.
        //     // First since the number of philosophers won't change during the simulation and is known at the creation of the array, there are few downsides to using an array.
        //     // Next, using a Vector calls the default constructor on the thread, which we can't make and causes an error.
        //     //std::thread philosophers [getNumberPhilosophers()];

        //     // Create one philosopher with "righthanded-ness" to prevent deadlock.
        //     std::thread philosophers = std::thread(simulatePhilosopher, 0, 1, 0); 
        //     philosophers.join();

        //     // create all the rest of the philosophers with "lefthanded-ness".
        //     // for (int i = 1; i < getNumberPhilosophers(); i++)
        //     // {
        //     //     philosophers[i] = std::thread(simulatePhilosopher, i, i, (i+1) % getNumberPhilosophers());
        //     // }

        //     // // wait for all philosophers to get done eating.
        //     // for (int i = 0; i < getNumberPhilosophers(); i++)
        //     // {
        //     //     philosophers[i].join();
        //     // }
        // }
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

