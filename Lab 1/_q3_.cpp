/*Q3. Create a C++ class Box that uses dynamic memory allocation for an integer. Implement the
Rule of Three by defining a destructor, copy constructor, and copy assignment operator.
Demonstrate the behavior of both shallow and deep copy using test cases.*/

#include <iostream>
using namespace std;

class Box{
    int *number;
    public:
    Box(){
        number = new int;
    }

    Box(int n){
        number = new int;
        *(this->number) = n ;
    }

    Box(const Box& copy){
        number = new int;
        *(this->number) = *(copy.number) ;
    }

    Box& operator=(const Box& other){
        if(this == &other)
        return *this;

        *(this->number) = *(other.number);
    }

    void setnum(int n){
        *number = n;
    }
    void display(){
        cout << *number << endl;
    }

    ~Box(){
        delete number;
    }
};

int main(){
    Box b1(10);
    Box b2(b1);
    Box b3;
    b3 = b2;

    cout << "b1:" ; b1.display();
    cout << "b2:" ; b2.display();
    cout << "b3:" ; b3.display();

    b1.setnum(99);

    cout << "After Changing: " << endl;
    cout << "b1:" ; b1.display();
    cout << "b2:" ; b2.display();
    cout << "b3:" ; b3.display();
    return 0;
}

/*Without a custom copy constructor and copy asignment operator default copy consturcotr would be initiated that reults in shallow copy.Which can lead to 
1.If b1 is changed it also affect b2 and b3 .
2.All objects (b1, b2, b3) will point to the same int.
3.double-deletion or data corruption.*/

