#include <thread>
#include <iostream>
#include <Philosopher.h>
//#include <vector>

using namespace Philosophers;

void simulateDeadlock()
{
    initialize();
    std::thread philosophers[NUMBERPHILOSOPHERS];
    for (int i = 0; i < NUMBERPHILOSOPHERS; i++)
    {
        philosophers[i] = std::thread(simulate, i, i, (i + 1) % NUMBERPHILOSOPHERS);
    }
    for (int i = 0; i < NUMBERPHILOSOPHERS; i++)
    {
        philosophers[i].join();
    }
    teardown();
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


int main()
{
    simulateNoDeadlock();
    //simulateDeadlock();
    return 0;
}