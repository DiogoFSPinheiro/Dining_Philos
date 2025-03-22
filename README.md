# Dining Philosophers Problem 🍽️
The Dining Philosophers is a classic concurrency problem introduced by Edsger Dijkstra to illustrate synchronization challenges in multithreaded programming. The problem involves five philosophers sitting around a circular table, alternating between thinking and eating.

🏛️ The Problem Setup
Each philosopher needs two forks (one on their left and one on their right) to eat.

* There are only five forks, so they must be shared.

* Philosophers must avoid deadlocks (where everyone is waiting forever) and starvation (where some never get to eat).

⚙️ Key Synchronization Concepts

* Mutexes & Semaphores: Used to control fork access.

* Resource Hierarchy: Preventing circular wait conditions.

* Asymmetrical Solutions: Avoiding all philosophers picking up forks simultaneously.

# My Implementation 🚀
This repository contains my solution to the Dining Philosophers problem using C, focusing on thread synchronization with pthread_mutex and avoiding deadlocks with efficient resource management.
