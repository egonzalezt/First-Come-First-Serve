# First-Come-First-Serve

## What is FCFS?

First come first serve (FCFS) scheduling algorithm simply schedules the jobs according to their arrival time. The job which comes first in the ready queue will get the CPU first. This algorithm is a Non-preemptive Scheduling the main reason is because it not interrupt a process running CPU in the middle of the execution. Instead, it waits till the process completes its CPU burst time, and then it can allocate the CPU to another process. 

## How we implemented

FCFS use a queue to push the process and give resources to the first process in the queue than when the first process is finished it starts the next process and so forth, for that reason we define a set of process and add in a queue to illustrate how First come First serve works.

### Problems with this Algorithm

* The scheduling method is non-preemptive, the process will run to the completion.

* Due to the non-preemptive nature of the algorithm, the problem of starvation may occur.

* Although it is easy to implement, however, it is poor in performance since the average waiting time is higher as compared to other scheduling algorithms.

## Try it

### Prerequisites
To see how this program works install C++ on your computer using GCC compiler 

[Visit GCC website](https://gcc.gnu.org/)


* Linux
  ```bash
    sudo apt-get update

    sudo apt install build-essential

    gcc --version

  ```

* Windows
  [Follow instructions provided by Visual Studio Code Team](https://code.visualstudio.com/docs/cpp/config-mingw)
  
### Usage 
 
If you are working on Linux or OSX you need to compile the required files to run the program.
 
```bash
 g++ -o FCFS FCFS.cpp main.cpp
 g++ -o bubbleSort bubbleSort.cpp
 g++ -o mergeSort mergeSort.cpp
```

And in the commands.txt file put this commands

* ls
* ./bubbleSort
* ./mergeSort
* mkdir itworks

If you are working on Windows compile the files and run it

```bash
 g++ -o FCFS FCFS.cpp main.cpp
 g++ -o bubbleSort bubbleSort.cpp
 g++ -o mergeSort mergeSort.cpp
```

To run it just put on the terminal ./FCFS