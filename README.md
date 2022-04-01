# philosophers

https://en.wikipedia.org/wiki/Dining_philosophers_problem

https://www.youtube.com/watch?v=dOVdsd31WNg

https://docs.oracle.com/cd/E19253-01/816-5137/sync-11157/index.html

https://see.stanford.edu/materials/icsppcs107/23-Concurrency-Examples.pdf

https://homes.cs.washington.edu/~arvind/cs422/lectureNotes/deadlock-6.pdf

https://thispointer.com/posix-detached-vs-joinable-threads-pthread_join-pthread_detach-examples/

http://lass.cs.umass.edu/~shenoy/courses/fall12/lectures/Lec10.pdf

####  mutex ou type atomic :

https://stackoverflow.com/questions/46340762/do-i-need-a-mutex-to-protect-a-int-value-which-could-be-get-set-via-sysfs

https://cboard.cprogramming.com/c-programming/151304-do-i-need-mutex-if-im-only-sharing-int-between-threads.html

http://www.alexonlinux.com/do-you-need-mutex-to-protect-int

#### Disclaimer
The goal's project was not really to solve the dinning philosophers problem.
Because of theses rules in the subject :

• Philosophers don’t speak with each other.

We can't avoid any death for ever. A death will occur sooner or later 

it may occur when a philo who just finished eating, eat a second time. Causing another philo to die.

So death may occur when philosophers go out of sync.
It heavily depend on CPU workload, and how the OS schedule thoses threads and processes.

It is mitigated by the sleeping time. However, when the sleeping time is too low.
Philosophers can go out of sync more often, causing some philosophers to starve and die.

Also using a sleeping time of 0 is an undefined behaviour. It relies on the OS implementation.
Most of OS just ignore `usleep(0)`, causing your thread/process to continue.
Leaving very few chances for other threads/processes to gain access to the ressource.
(In other words, philo eat two times in a row...)

Also I was not able to do [chandy/misra](https://en.wikipedia.org/wiki/Dining_philosophers_problem#Chandy/Misra_solution) algorithm for the same reason (`Philosophers don’t speak with each other`)
The rule will probably be misinterpreted during evaluation.

