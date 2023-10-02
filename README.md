# CS2_HW5

You will do this homework in teams of 3-4 students.  Pick a new team of students you haven't worked with previously.  Note that, starting with this Homework, if you do not work in teams you will lose up to 50% of the grade (you may NOT work individually).

## Introduction
In class, we talked about estimating efficiency by counting operations in a general way.  BUT, you can also do timings of things (although you may get some weird results).  Below is some code that makes use of the chrono package in C++ which lets us measure the time things take in our running code.

## The Code

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    const int ARRAY_SIZE = 10000;
    int myNumbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        myNumbers[i] = i;
    }
    for (int findN = 1000; findN < 10000; findN += 1000) {
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = 0;
        while (i < ARRAY_SIZE) {
            if (myNumbers[i] != findN) {
                i++;
            }
            else {
                cout << "Found " << findN << " at position " << i << "\n";
                break;
            }
        }
        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }
    return 0;
}
## What to Do
I want you to do two things.  First, I want you to run experiments to see how long the search in the code provided seems to take on each of your machines (at least one set of numbers from each member of the team).  Then, I want you to write a binary search to find the same elements that are found in the existing code and report the times for that, too.

The second thing to do would be to do some similar timing testing using the MyBag code I gave you in class, you can get the .h file here Download hereand the .cpp file here Download here.  Find a way to test contains and removeAll.

What to Submit
Submit your solution as a CPP file with your first and last name included in the file as a comment.   Add a long comment in your code explaining what results each of you got for your tests.  Also, write up what you may have learned from those experiments.