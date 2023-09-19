# Overview
An implementation of the classic dining philosopher deadlock problem. This was a school project for my operating systems class. The assignment was two parts, the first (Lab 5) was to create a senario that would deadlock. We were then to update the code to ensure that a deadlock did not happen and do a writeup. The writeup is included in this repo. 

##### The Dining Philosopher problem
There are five philosophers sitting around a circular table. In the middle of the table is a bowl of food which they will eat from when they get hungry, which will happen from time to time. In order to eat from this bowl they must first pick up two chopsticks which are placed between each pair of philosophers for a total of five chopsticks. When one picks up a chopstick, the philosopher next to him on the side he picks it up from cannot use it to eat until the one with the chopstick is done and puts the chopstick down again. 

It is not hard for the philosophers to get into a senario where each holds only one chopstick. This means each is purpetually waiting for another to relinquish theirs. This senario is a deadlock, which is the center of this problem. 

Any solution to this problem must prevent this deadlock and solutions are compared based on how well they manage the resources and facilitate the eating of food. 