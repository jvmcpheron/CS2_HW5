//Jane McPheron
//Teammates: Somayeh Najafi, Yassine Berrada, Tianyi Liang 


/* 
RESULTS FROM EVERYONE:
Jane McPheron

Regular Results:
Found 1000 at position 1000
That search zipped by in 0.01675 milliseconds.
Found 2000 at position 2000
That search zipped by in 0.004125 milliseconds.
Found 3000 at position 3000
That search zipped by in 0.00525 milliseconds.
Found 4000 at position 4000
That search zipped by in 0.006625 milliseconds.
Found 5000 at position 5000
That search zipped by in 0.007916 milliseconds.
Found 6000 at position 6000
That search zipped by in 0.009416 milliseconds.
Found 7000 at position 7000
That search zipped by in 0.010583 milliseconds.
Found 8000 at position 8000
That search zipped by in 0.011792 milliseconds.
Found 9000 at position 9000
That search zipped by in 0.013125 milliseconds.

Binary Search Results:
Number found at: 1000
That search zipped by in 0.031167 milliseconds.
Number found at: 2000
That search zipped by in 0.001 milliseconds.
Number found at: 3000
That search zipped by in 0.001 milliseconds.
Number found at: 4000
That search zipped by in 0.001083 milliseconds.
Number found at: 5000
That search zipped by in 0.000875 milliseconds.
Number found at: 6000
That search zipped by in 0.000916 milliseconds.
Number found at: 7000
That search zipped by in 0.000875 milliseconds.
Number found at: 8000
That search zipped by in 0.000917 milliseconds.
Number found at: 9000
That search zipped by in 0.000875 milliseconds.

Yassine Berrada

Linear Search: Found 1000 at position 1000
Linear search took 0.8713 milliseconds.
Binary Search: Found 1000 at position 1000
Binary search took 0.0004 milliseconds.
Linear Search: Found 2000 at position 2000
Linear search took 0.3618 milliseconds.
Binary Search: Found 2000 at position 2000
Binary search took 0.0002 milliseconds.
Linear Search: Found 3000 at position 3000
Linear search took 0.3179 milliseconds.
Binary Search: Found 3000 at position 3000
Binary search took 0.0002 milliseconds.
Linear Search: Found 4000 at position 4000
Linear search took 0.4488 milliseconds.
Binary Search: Found 4000 at position 4000
Binary search took 0.0003 milliseconds.
Linear Search: Found 5000 at position 5000
Linear search took 0.3433 milliseconds.
Binary Search: Found 5000 at position 5000
Binary search took 0.0004 milliseconds.
Linear Search: Found 6000 at position 6000
Linear search took 0.2897 milliseconds.
Binary Search: Found 6000 at position 6000
Binary search took 0.0002 milliseconds.
Linear Search: Found 7000 at position 7000
Linear search took 0.4478 milliseconds.
Binary Search: Found 7000 at position 7000
Binary search took 0.0003 milliseconds.
Linear Search: Found 8000 at position 8000
Linear search took 0.3735 milliseconds.
Binary Search: Found 8000 at position 8000
Binary search took 0.0004 milliseconds.
Linear Search: Found 9000 at position 9000
Linear search took 0.3707 milliseconds.
Binary Search: Found 9000 at position 9000
Binary search took 0.0004 milliseconds.

Somayeh Najafi

Found 1000 at position 1000
That search zipped by in 3.1218 milliseconds.
Found 2000 at position 2000
That search zipped by in 0.5252 milliseconds.
Found 3000 at position 3000
That search zipped by in 0.3329 milliseconds.
Found 4000 at position 4000
That search zipped by in 0.3768 milliseconds.
Found 5000 at position 5000
That search zipped by in 0.4008 milliseconds.
Found 6000 at position 6000
That search zipped by in 0.5227 milliseconds.
Found 7000 at position 7000
That search zipped by in 0.5698 milliseconds.
Found 8000 at position 8000
That search zipped by in 0.6201 milliseconds.
Found 9000 at position 9000
That search zipped by in 0.3899 milliseconds.

Tianyi Liang 
Found 1000 at position 1000
That search zipped by in 0.016792 milliseconds.
Found 2000 at position 2000
That search zipped by in 0.003375 milliseconds.
Found 3000 at position 3000
That search zipped by in 0.004458 milliseconds.
Found 4000 at position 4000
That search zipped by in 0.005625 milliseconds.
Found 5000 at position 5000
That search zipped by in 0.006792 milliseconds.
Found 6000 at position 6000
That search zipped by in 0.007958 milliseconds.
Found 7000 at position 7000
That search zipped by in 0.009125 milliseconds.
Found 8000 at position 8000
That search zipped by in 0.010708 milliseconds.
Found 9000 at position 9000
That search zipped by in 0.011542 milliseconds.

*/

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


int binary_search(int arr[],int size, int target) {

    int left = 0;
    int right = size;

    while (left <= right) {

        int mid = left+(right-left)/2;

        if (arr[mid] == target) {

            cout << "Number found at: "<< mid << endl;
            return mid; 
        } else if (arr[mid] < target) {

            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    return -1; 
}

int main() {
    const int ARRAY_SIZE = 10000;
    int myNumbers[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        myNumbers[i] = i;
    }
    for (int findN = 1000; findN < 10000; findN += 1000) {
        high_resolution_clock::time_point startTime = high_resolution_clock::now();
        int i = 0;


        //NEW BINARY SEARCH
        int result = binary_search(myNumbers, ARRAY_SIZE, findN);


        high_resolution_clock::time_point stopTime = high_resolution_clock::now();
        duration<double, std::milli> timeTaken = (stopTime - startTime);
        cout << "That search zipped by in " << timeTaken.count() << " milliseconds.\n";
    }
    



}