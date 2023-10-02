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