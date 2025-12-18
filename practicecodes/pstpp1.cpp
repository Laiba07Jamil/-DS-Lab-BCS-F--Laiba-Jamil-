#include <iostream>
#include <string>
using namespace std;

class Customer{
    string name;
    string month;
    int date;
    int hanger;
    public:
    Customer(string n , string m ,int d){
        name = n ;
        month = m;
        date = d;
    }
    Customer(int hanger) {hanger = hanger;}
    Customer() {}
    char* getname() {return &name;}
    string getmonth() {return month;}
    int getdate() {return date;}
    int gethanger() {return hanger;}
    void sethanger(int h){hanger = h;}
};

int getmonth(string m){
    if(m == "January") return 1;
    else if(m == "February") return 2;
    else if (m == "March") return 3;
    else if(m == "April") return 4;
    else if(m == "May" ) return 5;    
    else if(m == "June" ) return 6;    
    else if(m == "July" ) return 7;    
    else if(m == "August" ) return 8;    
    else if(m == "September" ) return 9;    
    else if(m == "October" ) return 10;    
    else if(m == "November" ) return 11;    
    else if(m == "December" ) return 12;  
    else return 0;  

}

void sort(Customer** customers , int n){
    for(int i =0 ; i < n - 1 ; i++){
        int minindex = i;
        for(int j = i + 1 ; j < n ; j++){
            if(customers[j]->getdate() < customers[minindex]->getdate()){
                minindex = j;
            }
            else if(customers[j]->getdate() == customers[minindex]->getdate()){
                if(strlen(customers[j]->getname()) > strlen(customers[minindex]->getname())){
                    minindex = j;
                }
            }
            else if(customers[j]->getdate() == customers[minindex]->getdate()){
                int getjmonth = getmonth(customers[j]->getmonth());
                int getminmonth = getmonth(customers[minindex]->getmonth());
                if(getjmonth < getminmonth){
                    minindex = j;
                }

            }
        }
        Customer* temp = customers[i];
        customers[i] = customers[minindex];
        customers[minindex] = temp;
    }

    for(int i = 1 ; i <= n ; i++){
        customers[i]->sethanger(1);
        customers[i]->sethanger(2);
        customers[i]->sethanger(3);
        customers[i]->sethanger(4);
        customers[i]->sethanger(5);
    }
}

int search(Customer** customers , int n , int target){
    int left = 0 ;
    int right = 0;
    bool falg = false;
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(customers[mid]->gethanger() == target){
            cout << "Target element is found." << endl;
            falg = true;
            break;
        }
        else if(customers[mid]->gethanger() > target){
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }
    if(!falg){
        cout << "Not found." << endl;
        return -1;
    }
}

int main(){
    int n = 5;
    Customer* customers[5];
    customers[0] = new Customer{"Mubeen" , "September" ,9};
    customers[1] = new Customer{"Laiba" , "August" ,7};
    customers[2] = new Customer{"Laiba" , "August" ,7};
    customers[3] = new Customer{"Laiba" , "August" ,7};
    customers[4] = new Customer{"Laiba" , "August" ,7};

}