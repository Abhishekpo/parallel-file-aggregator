# Parallel File Aggregator (C / Linux / POSIX Threads)

A C-based tool that computes aggregate sums across multiple input files.

Includes:
- Sequential implementation
- Multithreaded implementation using POSIX threads (pthreads)

## Overview

Each input file contains integers (positive and negative).  
The program outputs:

<negative_sum> <positive_sum>

The threaded version creates one thread per file and aggregates results safely after `pthread_join`.

## Build

```bash
#Run
make


Sequential version:

```bash
./sum-files data/sample1.txt

Multithreaded version:
./sum-files-threaded data/sample1.txt

