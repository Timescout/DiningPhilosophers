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



        ///// private functions. /////

        /// @brief The function that simulates a philosopher. This is run using multithreading.
        /// @param philosopherNumber The label for this philosopher. I.e "Philosopher 1, Philosopher 2, etc."
        void simulatePhilosopher(int philosopherNumber, std::mutex* chopstickOne, std::mutex* chopstickTwo)
        {
            std::cout << "Philosopher number " << philosopherNumber << " reporting.\n";
            //std::cout << "Chopstick one is " << chopstickOne->try_lock() << ".\n";
            //std::cout << "Chopstick two is " << chopstickTwo->try_lock() << ".\n";
        }



    public:
        ///// Constructors and Deconstructors /////

        /// @brief Argumented constructor
        /// @param numberPhilosophers The number of philosophers simulated. Must be at least 2.
        /// @param simulationTime The minimum time the simulation will run for.
        /// @param simulationTimeoutTime The maximum time the simulation will run for.
        /// @warning A number of threads will run equal to numberPhilosophers.
        PhilosopherSimulation(unsigned int numberPhilosophers, unsigned int simulationTime, unsigned int simulationTimeoutTime) 
        {
            setNumberPhilosophers(numberPhilosophers);
            setSimulationTimeFrame(simulationTime, simulationTimeoutTime);
        }

        /// I like to include the default constructed values as their own variables so I can use them for testing.
        inline const static int DEFAULTnUMBERpHILOSOPHERS = 5, DEFAULTsIMULATIONtIME = 10, DEFAULTsIMULATIONtIMEOUTtIME = 20;
        PhilosopherSimulation() :
            PhilosopherSimulation(DEFAULTnUMBERpHILOSOPHERS, DEFAULTsIMULATIONtIME, DEFAULTsIMULATIONtIMEOUTtIME)
        {}

        ~PhilosopherSimulation() {}



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
            if ( newSimulationTimeoutTime < newSimulationTime) { throw std::logic_error("simulation time longer than simulation timeout time"); }
            simulationTime_ = newSimulationTime;
            simulationTimeoutTime_ = newSimulationTimeoutTime;
        }

        void simulateDeadlock(bool Deadlock = true) 
        {
            // Create Chopsticks
            std::vector<std::mutex*> chopsticks(getNumberPhilosophers(), nullptr);
            for (auto &i : chopsticks) { i = new std::mutex(); }

            // Create Philosophers
            std::vector<std::thread*> philosophers;
            for (int i = 0; i < getNumberPhilosophers(); i++)
            {
                if (i == 0 && !Deadlock)
                { // Create one philosopher with "righthanded-ness" to prevent deadlock.
                    philosophers.push_back(new std::thread(
                        &PhilosopherSimulation::simulatePhilosopher, // Thread function
                        this, // this pointer which runs the thread on a member function
                        0, chopsticks[1], chopsticks[0] // function arguments
                    ));
                }
                else { // create all the rest of the philosophers with "lefthanded-ness".
                    philosophers.push_back(new std::thread(
                        &PhilosopherSimulation::simulatePhilosopher, // Thread function
                        this, // this pointer which runs the thread on a member function
                        i, chopsticks[i], chopsticks[(i+1) % getNumberPhilosophers()] // function arguments
                    ));
                }
            }

            // Wait for threads to finish and clean up pointers.
            for (auto &i : philosophers) { i->join(); delete i; i = nullptr; }
            for (auto &i : chopsticks) { delete i; i = nullptr; }
        }

        void simulateNoDeadlock() 
        {
            simulateDeadlock(false); // I did this because code reuse!
        }
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
        */
};