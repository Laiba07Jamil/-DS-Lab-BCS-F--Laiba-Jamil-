#include <iostream>
using namespace std;

class Runner{
    string name;
    int time;
    public:
    Runner(string n , int t){
        this->name = n;
        this->time = t;
    }

    Runner(){}
    void set_name(string n){name = n;}
    void set_time(int t){time = t;}
    string getname(){return name;}
    int gettime(){return time;}

    void display(){
        cout <<   name << " = "<< time << " seconds" << endl;
        }
};

void mergerSort(Runner** runner , int low ,int mid , int high){
    int n1 = mid - low + 1;
    int n2 = high - mid;

    Runner** arr1 = new Runner*[n1]; 
    Runner** arr2 = new Runner*[n2];

    for(int i = 0 ; i < n1 ; i++){
        arr1[i] = runner[low + i];
    }
    for(int i = 0 ; i < n2 ; i++){
        arr2[i] = runner[mid + 1 + i];
    }
    int i = 0 , j = 0 , k = low; 
    while(i < n1 && j < n2){
        if(arr1[i]->gettime() <= arr2[j]->gettime()){
            runner[k] = arr1[i];
            i++;
        }
        else{
            runner[k] = arr2[j];
            j++;
        }
        k++;
    }
     while(i < n1){
        runner[k] = arr1[i];
        i++;
        k++;
     }
     while(j < n2){
        runner[k] = arr2[j];
        j++;
        k++;
     }

     delete[] arr1;
     delete[] arr2;
}

void merge(Runner** runner , int low , int high){
    if(low < high){
        int mid = low + (high - low) / 2;
        merge(runner,low ,mid);
        merge(runner,mid + 1 , high);
        mergerSort(runner,low,mid,high);
    }
}

int main(){
    int n = 10;
    string name ;
    int t;
    Runner* runner[10];
    for(int i = 0 ; i < n ; i++){
        runner[i] = new Runner();
    }
    for(int i = 0 ; i < n ; i++){
        cout << "Enter name and finishing time for runner " << i + 1 << " :";
        cin >> name >> t;
        runner[i]->set_name(name);
        runner[i]->set_time(t);
    }

    merge(runner , 0 , n - 1);
    for(int i = 0 ; i < 5 ; i++){
        cout << i + 1 << ". " ;
         runner[i]->display();
    }

}
