# Coding with Github Copilot 

You can use GitHub Copilot to get autocomplete-style suggestions from an AI pair programmer as you code. I put the tool to test and tried using it to solve problem 7 in the Questions Sheet.

## Installation

I signed in using my university email and I got to use the tool foe free. I downloaded its extension to the code editor I am using (Visual Studio Code) and activated it.

## Experience

First off, I added the standard iostream library and specified the namespace I am using to std. Then, I added some comments to describe what the function I want to write should do.
```c++
#include <iostream>
using namespace std;

/* Build a game with teddy bears. It starts when I give you some bears. You can then 
give back some bears, but you must follow these rules (n is the number of bears that you have):
1. If n is even, then you may give back exactly n / 2 bears.
2. If n is divisible by 3 or 4, then you may multiply the last two digits of n and give back this many 
bears. (By the way, the last digit of n is n % 10, and the next-to-last digit is ((n % 100) / 10).
3. If n is divisible by 5, then you may give back exactly 42 bears.
The goal of the game is to end up with EXACTLY 42 bears.*/
```

After typing out the function's header, Copilot automatically gave me suggestions for the function's body. You can swap through the different suggestions using (Alt+]). To select a suggestion, you should press the Tab button and then Enter.
```c++
bool bears(int n) {
    if (n == 42) {
        return true;
    }
    if (n < 42) {
        return false;
    }
    if (n % 2 == 0) {
        if (bears(n / 2)) {
            return true;
        }
    }
    if (n % 3 == 0 || n % 4 == 0) {
        if (bears((n % 100) / 10 * (n % 10))) {
            return true;
        }
    }
    if (n % 5 == 0) {
        if (bears(n - 42)) {
            return true;
        }
    }
    return false;
}
```

## Did It Work Well?
It works pretty well. The code runs and solves most test cases correctly. However, It doesn't take into consideration the possibility that one of last two digits of the number may be equal to zero, so it gives a wrong result in such cases. Overall, it was a really interesting experience using Copilot.
```c++
int main() {
    cout << bears(84) << endl; // should be 1 and gives 1
    cout << bears(53) << endl; // should be 0 and gives 0
    cout << bears(250) << endl; // should be 1 but gives 0
    return 0;
}

```

## My Evaluation
This is a really helpful technology in my opinion. It can help with the code of small and repititive functions but for big or complicated ones you have to double check if it works correctly with corner test cases as some details might slip out of its scope.
