#include <iostream>
using namespace std;

class Student{
    string Id;
    int age;
    string name;
    float gpa;
    public:
    Student() {}
    Student(string id , int age , string n, float gpa){
        this->age = age;
        this->name = n;
        this->gpa = gpa;
        this->Id = id;
    }

    string getname(){return name;}
    int getage(){return age;}
    float getgpa(){return gpa;}
    string getid(){return Id;}    
};

void display(Student** students , int n ){
        for(int i = 0 ; i < n ; i++){
            cout << "Record of student " << i + 1 << endl;
            cout << "GPA: " << students[i]->getgpa();
            cout << "name " << students[i]->getname();
            cout << "age: " << students[i]->getage();
            cout << "id: " << students[i]->getid();
        }
    }

string lookup_GPA(Student** students , int n , float target){
    int left = 0 ;
    int right = n - 1;
    bool found = false;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(students[mid]->getgpa() == target){
            int l = mid , r = mid;
            while(l >= 0 && students[l]->getgpa() == target){
                cout << "Student with GPA " << target << "ID -> " << students[l]->getid() << endl;
                l--;  
            }
            while(r < n && students[r]->getgpa() == target){
                cout << "Student with GPA " << target << "ID -> " << students[l]->getid() << endl;
                r++;
      }
      found = true;
      break;
        }
        else if (students[mid]->getgpa() < target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
}

void sort_GPA(Student** students , int n){
        for(int i = 0 ; i < n - 1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(students[j]->getgpa() < students[j+1]->getgpa()){
                Student* temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;

            }
        }
    }
}

int* resize(int *arr , int older , int news){
    if(older == news){return arr;}
    int* newarr = new int[news];
    int limits;
    if(older < news){limits = older;}
    else{limits = news;}
    for(int i = 0 ; i < limits ; i++){
        newarr[i] = arr[i];
    }

    delete[] arr;
    return newarr;
}

void sort(int *arr ,int n){
    for(int i = 0 ; i < n -1 ; i++){
        for(int j = 0 ; j < n - i - 1 ; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



void function(int A[],int m , int B[],int n ,int C[]){
    
    sort(B,n);
    int* C = new int[m];
    for(int i = 0 ; i < m ; i++){
        C[i] = A[i];
    }

    C = resize(C , m , n);
    for(int i = m ;i < n ; i++){
        C[i] = B[i] ;
    }
    sort(C,n);


}
int main(){
    int n = 5;
    Student* students[5];
    students[0] = new Student("24k -0812" , 15 , "Laiba" , 3.5);
    students[1] = new Student("24k -0668" , 10 , "Ldvd" , 1.2);
    students[2] = new Student("24k -0854" , 16 , "Lava" , 4);
    students[3] = new Student("24k -0654" , 17 , "Laeba" , 3);
    students[4] = new Student("24k -1021" , 18 , "Laeba" , 2.1);

    
    float target;
    cout << "Enter the gpa to search: ";
    cin >> target;
    
    
}