#include <iostream>
#include <cassert>

using namespace std;

int rollDie(int low = 1, int high = 6) {
    assert(high >= low);
    return (rand() % (high - low + 1)) + low;
}

int main() {
    cout << rollDie() << endl;
    return 0;
}

/** SOLUTIONS

a) 
The fuction returns a random number between low and high (low <= num <= high)
assert() makes sure that high is equal or bigger than low (if the expression inside the assert statement is false, an error occurs)

b)
The function has 3 signatures:
> The number of formal parameters (low and high)
> The order and type of formal parameters (low and high)
> The name of the function (rollDie)

c) 
Yes, it is possible, as long as the formal parameters of the function are
different from the ones in the current rollDie() (2 int type parameters) 
*/
