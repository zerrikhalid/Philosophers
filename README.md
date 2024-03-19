## Philosophers

The Philosophers project introduces you to the basics of threading, processes, and synchronization mechanisms such as mutexes and semaphores. You'll implement the dining philosophers problem, where philosophers sit at a round table, alternating between eating, thinking, and sleeping, while ensuring that they do not starve or encounter deadlocks.

## Table of Contents
* [Overview](#about)
* [Installation](#installation)
* [Mandatory Part](#mandatory-part)
  * [description](#description)
  * [usage](#usage)
  * [Implementation](#implementation)
* [bonus Part](#bonus-Part)
  * [description](#description)
  * [usage](#usage)
  * [Implementation](#implementation)

## Overview

In the dining philosophers problem, multiple philosophers sit around a table, with a bowl of spaghetti in the center. Each philosopher must alternate between three states: eating, thinking, and sleeping. To eat, a philosopher needs to pick up two adjacent forks. However, to prevent deadlocks, philosophers must coordinate their actions to ensure that they do not starve or encounter resource contention.

## Installation

To install the project, clone the repository and navigate to the project directory. Then, compile the project using the following command:

```bash
make
```

## Mandatory Part

### description

In the mandatory part of the project, you'll implement the dining philosophers problem using threads and mutexes. Each philosopher will be represented by a thread, and each fork will be protected by a mutex to prevent race conditions. The goal is to ensure that philosophers can eat, think, and sleep without encountering deadlocks or starvation.

### usage

To run the mandatory part of the program, compile the philo executable with the provided Makefile and specify the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- number_of_philosophers: The number of philosophers and forks.
- time_to_die: The time in milliseconds since the start of a philosopher's last meal or the beginning of the simulation after which they die.
- time_to_eat: The time in milliseconds it takes for a philosopher to eat.
- time_to_sleep: The time in milliseconds a philosopher spends sleeping.
- number_of_times_each_philosopher_must_eat (optional): The number of times each philosopher must eat before the simulation stops.

### Implementation

- Each philosopher is represented by a separate thread.
- Mutexes are used to protect access to forks to prevent race conditions and deadlocks.
- Philosophers alternate between eating, thinking, and sleeping, adhering to the specified time intervals.
- The program logs the state transitions of each philosopher, including when they take forks, eat, sleep, think, or die.

## Bonus Part

### description

In the bonus part of the project, you'll implement the dining philosophers problem using processes and semaphores. Each philosopher will be represented by a separate process, and the forks will be represented by a semaphore to track availability. The main process will coordinate the philosophers' actions without being a philosopher itself.

### usage

To run the bonus part of the program, compile the philo_bonus executable with the provided Makefile and specify the following arguments:

```bash
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
- number_of_philosophers: The number of philosophers and forks.
- time_to_die: The time in milliseconds since the start of a philosopher's last meal or the beginning of the simulation after which they die.
- time_to_eat: The time in milliseconds it takes for a philosopher to eat.
- time_to_sleep: The time in milliseconds a philosopher spends sleeping.
- number_of_times_each_philosopher_must_eat (optional): The number of times each philosopher must eat before the simulation stops.

### Implementation

- Each philosopher is represented by a separate process.
- Semaphores are used to track the availability of forks and prevent deadlocks.
- The main process coordinates the philosophers' actions, ensuring that they can eat, think, and sleep without encountering deadlocks or starvation.
- The program logs the state transitions of each philosopher, including when they take forks, eat, sleep, think, or die.

