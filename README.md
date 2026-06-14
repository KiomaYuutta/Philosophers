<i>This project has been created as part of the 42 curriculum by dide-alm.</i>

**Description**

The Philosophers project is an introduction to threading and process synchronization in C. It is a variation of the famous Dining Philosophers Problem, originally formulated by Edsger Dijkstra.

The goal of this project is to learn how to create threads, use mutexes, and deeply understand how to avoid concurrent programming pitfalls like data races, deadlocks, and starvation while managing shared resources (forks) among multiple entities.

**Instructions**

Compilation

The project includes a Makefile that compiles the source files with the -Wall -Wextra -Werror flags.

To compile the program, run:

make

Execution

The program takes 4 required arguments and 1 optional argument

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

<pre>
Argument		Description
number_of_philosophers	The number of philosophers and forks.
time_to_die (in ms)	If a philosopher doesn't start eating time_to_die ms after their last meal, they die.
time_to_eat (in ms)	The time it takes for a philosopher to eat (requires holding two forks).
time_to_sleep (in ms)	The time a philosopher spends sleeping.
[must_eat] (Optional)	If all philosophers eat at least this many times, the simulation stops successfully.
</pre>
<br>

Usage Examples

Example 1 (Philosopher dies):
	./philo 1 800 200 200

	(Philosopher 1 dies because there is only 1 fork available, making it impossible to eat).


Example 2 (No one dies):

	./philo 4 410 200 200

Example 3 (Simulation stops after eating limit):

    ./philo 5 800 200 200 7

**Resources**

Documentation & Articles

    Dining Philosophers Problem - Wikipedia
    POSIX Threads Programming Guide
    Threads, Mutexes and Concurrent Programming in C


Use of AI

AI was utilized during the development of this repository for the following tasks:

    Documentation Boilerplate: Generating the initial structure, tables, and formatting for this README.md file to ensure clarity and scannability.

    Code Structuring: Clarifying the relationship between thread initialization and mutex locking structures to prevent deadlocks conceptually before implementation.