# The Dining Philosophers Simulation
## Building the Code
This project uses cMake for its build process. All commands will be relative to the git repository. Use the following commands to build:

> cmake -B build

This will create a new folder called build and generate cmake files in that folder.

>cmake --build build

This will build the project and put the executibles in the build folder.

>./build/main

>./build/tests

These will run the main program and the unit tests respectivly. 

## The Project
This project was an assignment for my operating systems class in college and I returned to improve it. The project implements a solution to the Dining Philosophers problem which is a theoretical concurrency problem that creates and solves a deadlock.

The problem is this: there are five philosophers sat at a round table with five chopsticks, one between each pair of philosophers. There is some food in the middle of the table which a philosopher can eat if they have two chopsticks. Since there are the same number of philosophers and chopsticks if one of them is eating another cannot be eating. 

This relates to programming like so: say there are some number of processes or threads and resources that they must share. If each process greedly grabbed as many resources as they could without some way to prevent deadlocks, that would be like each philosopher grabbing a single chopstick. If every chopstick is held without anyone letting go, noone gets to eat and the system deadlocks. 

The assignment was to implement a way to prevent this from happening. Each philosopher is a thread, each chopstick is a mutex, which is a lock for resources, and there are the same number of each. They can "eat" which is represented by the thread sleeping for some time. 

There are many solutions to this problem each with their tradeoffs. The solution I implemented is to designate philosophers either as "left handed" or "right handed". It has been shown that as long as one philosopher is opposite handed to all the rest, deadlock is impossible.  I have included the writeup for that assignment in this repository but it talks about old code that has been rewritten and is more in-depth about different solutions and their tradeofs.

The main program will show how this works: it will run the same simulation twice. One time where one philosopher is opposite handed and another where all philosophers are same handed. The status of the chopsticks is printed to the screen, and the simulation will time out and force quit after two minutes when deadlock occurs. 