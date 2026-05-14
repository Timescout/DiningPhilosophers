explination of problem, including deadlocks, multithreading, overview of the theoretical problem.

explination of objects used in the code, including mutex, threads, 

approaches to solving the problem including the one I implement.

Sources, including the paper I cite.

As proccessing power grew the number of cores in computers increased. High performance programs started to use more than one core to accomplish tasks in parallel to reduce the overall time it took to complete a task, like baking two cakes in two ovens at the same time rather than one oven twice. A program does this by asking the operating system to run on more than one core which the operating system then does if another core is avaliable. This process is called multithreading, as the indiviual processes, the "cakes", are individually called threads. When I was in my operating systems class in college we covered how the operating system handles multithreading and this project was the capstone of that unit. 

Multithreading is not as simple as cutting a project up into parts and running each part on a separate thread. This project will only cover one of many challenges it creats which is the problem of deadlocking. This is when two separate threads prevent each other from continuing. 




# Overview
An implementation of the classic dining philosopher deadlock problem. This was a school project for my operating systems class. The assignment was two parts, the first (Lab 5) was to create a senario that would deadlock. We were then to update the code to ensure that a deadlock did not happen and do a writeup. The writeup is included in this repo. 

##### The Dining Philosopher problem
There are five philosophers sitting around a circular table. In the middle of the table is a bowl of food which they will eat from when they get hungry, which will happen from time to time. In order to eat from this bowl they must first pick up two chopsticks which are placed between each pair of philosophers for a total of five chopsticks. When one picks up a chopstick, the philosopher next to him on the side he picks it up from cannot use it to eat until the one with the chopstick is done and puts the chopstick down again. 

It is not hard for the philosophers to get into a senario where each holds only one chopstick. This means each is purpetually waiting for another to relinquish theirs. This senario is a deadlock, which is the center of this problem. 

Any solution to this problem must prevent this deadlock and solutions are compared based on how well they manage the resources and facilitate the eating of food. 


