# Parallel File Aggregator (C / Linux / POSIX Threads)

A C-based file processing tool that computes aggregate sums across multiple input files.  
This project includes both a sequential implementation and a multithreaded implementation using POSIX threads (pthreads).

---

## Overview

Each input file contains integers (positive and negative values).

The program computes:

- Total sum of negative numbers
- Total sum of positive numbers

Output format:


The multithreaded version creates **one thread per input file**, processes them concurrently, and aggregates results safely in the main thread after `pthread_join`.

No shared data is modified concurrently, preventing race conditions.

---

## Project Structure

parallel-file-aggregator/
│
├── src/
│ ├── sum-files.c
│ └── sum-files-threaded.c
│
├── data/
│ ├── sample1.txt
│ └── large.txt
│
├── Makefile
└── README.md


---

## Build Instructions (Linux / Ubuntu / WSL)

Ensure `gcc` is installed.

Compile both versions:

```bash
make

This generates:

sum-files (sequential version)

sum-files-threaded (multithreaded version)

## Run Instructions

 Sequential Version
./sum-files data/sample1.txt

Multithreaded Version
./sum-files-threaded data/sample1.txt


You may provide multiple files:

./sum-files-threaded data/sample1.txt data/large.txt


Example
./sum-files-threaded data/large.txt


Output:

-1265880 1246109  


(Values will vary depending on input file.)

##Concurrency Design

-One thread is created per input file.

-Each thread computes local positive and negative sums.

-Results are returned via dynamically allocated structures.

-The main thread aggregates results after pthread_join.

-No mutex synchronization is required because shared state is not modified concurrently.

##Memory Safety

-Dynamically allocated memory is freed after use.

-Designed to run cleanly under Valgrind with no memory leaks.

#Example:

valgrind ./sum-files-threaded data/sample1.txt

##Technologies Used

C (C11 standard)

POSIX Threads (pthread_create, pthread_join)

GCC compiler

Linux / Ubuntu (WSL)

Makefile build system

Skills Demonstrated

Multithreading in C

Parallel file processing

Linux systems programming

Safe memory management

Command-line application design

##Author
Abhishek Poudel
