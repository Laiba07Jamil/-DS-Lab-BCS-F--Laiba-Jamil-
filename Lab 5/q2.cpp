/*Write a simple C++ program that demonstrates direct recursion. Create a function
printNumbers(int n) that prints numbers from n down to 1 by calling itself
directly.
2. Next, demonstrate indirect recursion by creating two functions, functionA(int n)
and functionB(int n). functionA should call functionB, and functionB
should call functionA, forming a cycle that prints numbers in a specific pattern.
Ensure both programs have a base condition to prevent infinite loops.*/

#include<iostream>
using namespace std;

void print(int n){
    if(n < 1 ){
        return;
    }
    cout << n << " ";
    return print(n - 1);
}
void functionB(int n);

void functionA(int n){
    if(n < 1){
        return;
    }
    cout << n << " ";
    return functionB(n - 1);
}

void functionB(int n){
    if(n < 1){
        return;
    }
    cout << n << " ";
    return functionA(n - 1);
}

int main(){
    int n;
    cout <<"Enter the element to print: ";
    cin >> n;
    cout << "Type 1 recursion " << endl;
    print(n);
    cout << endl;
    cout << "Type 2 recursion " << endl;
    functionA(n);
}
