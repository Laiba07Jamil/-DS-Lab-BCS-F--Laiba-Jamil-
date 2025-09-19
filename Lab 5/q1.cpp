
#include <iostream>
using namespace std;

int Factorial(int n){
    if(n == 0 || n == 1){
        return n;
    }
    return n * Factorial(n - 1);
}

int main(){
    int n;
    cout <<"Enter the element for factorial: ";
    cin >> n;
    int fac = Factorial(n);
    cout << "The Factorial of " << n << " is : " << fac << endl;
}
