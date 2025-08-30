#include <iostream>
using namespace std;

class SafePointer{
    private:
    int* ptr;
    public:
    SafePointer() {
        ptr = new int ;
        *ptr = 0;
    }
    SafePointer(int n){
        ptr = new int;
        *(this->ptr) = n;
    }

    void setvalue(int value){
        *ptr = value;
    }

    int getvalue(){
        return *ptr;
    }

    SafePointer(const SafePointer& other){
        ptr = new int;
        *(this->ptr) = *(other.ptr);
    }

    ~SafePointer(){
        delete ptr;
    }

    
};

int main(){
    SafePointer students[5];
    for(int i = 0 ; i < 5 ; i++){
        int mark;
        cout << "Enter the marks of students " << i+1 << ":";
        cin >> mark;
        students[i].setvalue(mark);
    }

    for(int i = 0 ; i < 5 ; i++){
        cout << "Student " << i + 1 << ":"<< students[i].getvalue() << endl;
    }
    return 0 ;
}