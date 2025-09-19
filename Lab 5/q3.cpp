/*Implement a C++ function sumTail(int n, int total) that calculates the sum
of numbers from 1 to n using tail recursion. The recursive call should be the last
operation in the function.
2. Implement another function sumNonTail(int n) that calculates the same sum
using non-tail recursion. This function should perform an operation (e.g., addition) after
the recursive call returns. Compare the two implementations and explain the difference
in their call stacks.*/

#include <iostream>
using namespace std;

#include <iostream>

int sumTailHelper(int n, int total) {
    if (n == 0) {
        return total;
    }
    return sumTailHelper(n - 1, total + n);
}

int sumTail(int n) {
    return sumTailHelper(n, 0);
}

int sumNonTail(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sumNonTail(n - 1);
}


int main() {
    int n = 5;
    cout << "Sum using non-tail recursion: " << sumNonTail(n) << endl;
    return 0;
}
