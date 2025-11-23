#include <iostream>
using namespace std;

#define size 15

class StudentHashTable{
    string name[size];
    int roll_num[size];
    bool occupied[size];

    public:
    StudentHashTable(){
        for(int i = 0 ; i < size ; i++){
            occupied[i] = false;
        }
    }

    int hashfunction(int key){
        return key % size;
    }

    void InsertRecord(int key , string n){
        int index = hashfunction(key);
        int startindex = index;
        int i = 1;

        while(occupied[index]){
            if(roll_num[index] == key){
                name[index] = n;
                return;
            }
            index = (index + i * i) % size;
            if(index == startindex){
                cout << "Hash table is full." << endl;
            }
            i++;
        }

        roll_num[index] = key;
        name[index] = n;
        occupied[index] = true;
    }

    void SearchRecord(int num){
        int index = hashfunction(num);
        int i = 1;
        int startindex = index;

        while(occupied[index]){
            if(roll_num[index] == num){
                cout << "The student " << name[index] << " has roll number " << num << endl;
                cout << endl;
                return; 
            }
            index = (index + i * i ) % size;
            i++;
            if(index == startindex){
                break;
            }
        }
        cout << "Roll number not found." << endl;
        cout << endl;
    }

    void traverse(){
        for(int i = 0 ; i < size ; i++){
            if(!occupied[i]){
                continue;
            }
            cout << "[" << i << "]" ;
            cout << "(" << roll_num[i] << "," << name[i] << ")" << endl;
        }
        cout << endl;
    }
};


int main(){
    StudentHashTable students;
    students.InsertRecord(812 , "Laiba");
    students.InsertRecord(688 , "Simal");
    students.InsertRecord(852 , "Armeen");
    students.InsertRecord(654 , "Ariza");
    students.InsertRecord(827 , "Maryam");
    students.traverse();

    cout << "Searching..." << endl;
    students.SearchRecord(852);
    cout << "Searching..." << endl;
    students.SearchRecord(345);

}
