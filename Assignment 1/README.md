# COP4520-Assignment 1

## How to compile the program
Any OS
```
cd 'Assignment 1'
g++ mult-thread.cpp
```

## How to run the program
On Windows
```
.\a.exe
```

On UNIX OS
```
./a.out
```

## General Info
- Language: C++
- Algorithm Implementation: Sieve of Eratosthenes

<hr> 

## Assignment Report

  ### My approach
  Since getting my foot wet with threading and parallelizing was a little turbulent at first, I decided to create my solving algorithm on a single threaded solution first<sup>1*</sup>.
  I implemented a Sieve of Eratosthenes algorithm which on a single thread was running ~7secs. 
  
  For multiple threads I decided to the following steps:
  1. Divide the range 2-10^8 in 8 steps. With that, I could completely avoid having to worry about locks (or so I thought...)
  2. Adapt my implementation to run get the prime numbers on different threads, avoiding also being inefficient with my solution
  3. Write all the info gathered to the output file


  ### What went well:
  - I was able to properly separate the values and create the threads
  - After getting all the threads setup in a nice vector, they were all appropriatelly joined 

  ### What went wrong:
  - Without the locks, my implementation does not even run. A few times I was able to get it to finish running, but with super incorrect output
  - In general, I am very unsure what went wrong. When I came up with the idea of dividing the values, I thought I had figured it out. Maybe it was an issue with memory, or maybe handling the divided values.


  ### Conclusion
  I was able to come up with a somewhat efficient solution for the problem, but unable to implement it with multiple threads. Excited to get a better grasp of multi-threading in practice!

  ### (Extra: Feedback)
  This class so far has not gone over any examples of how to implement the theoritical ideas we go over lecture. Maybe having an intrduction would have saved us a lot of time in taking our first step and not spending so much on the basics.

<hr>

### *Note*
<sup>1*</sup> - *I left the file `single-thread.cpp` in the directory to demonstrate that I was able to create the logic corretly for this assignment. It should run in around ~7 seconds*