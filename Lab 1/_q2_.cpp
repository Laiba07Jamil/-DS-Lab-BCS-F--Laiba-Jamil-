/*Q2. Create a C++ class named "Exam" using DMA designed to manage student exam records,
complete with a shallow copy implementation? Define attributes such as student name, exam
date, and score within the class, and include methods to set these attributes and display exam
details. As part of this exercise, intentionally omit the implementation of the copy constructor and copy assignment 
operator. Afterward, create an instance of the "Exam" class, generate a
shallow copy, and observe any resulting issues?*/

#include <iostream>
using namespace std;

class Exam{
    private:
    string *name;
    int *exam_date;
    float *score;

    public:
    Exam(){
        name = new string;
        exam_date = new int;
        score = new float;
    }

    void setname(string n){
        *(this->name) = n;
    }

    void setexam_date(int date){
        *(this->exam_date) = date;
    }

    void setscore(float s){
        *(this->score) = s;
    }

    void display(){
        cout << "Name: " << *name << endl;
        cout << "Exam date: " << *exam_date << endl;
        cout << "Score: " << *score << endl;
    }

    ~Exam(){
        delete name;
        delete score;
        delete exam_date;
    }
};

int main(){
    Exam s1;
    s1.setname("Laiba");
    s1.setexam_date(5);
    s1.setscore(70.5);
    cout << "Record of student 1: " << endl;
    s1.display();

    Exam s2(s1);
    cout << "Record of student 2: " << endl;
    s2.display();

    s1.setname("Hassan");
    s1.setexam_date(15);
    s1.setscore(90.5);
    cout << "After Changes :" << endl;
    cout << "Record of student 1: " << endl;
    s1.display();
    cout << "Record of student 2: " << endl;
    s2.display();


}