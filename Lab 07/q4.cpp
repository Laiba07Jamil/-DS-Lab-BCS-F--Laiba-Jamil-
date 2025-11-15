#include <iostream>
using namespace std;

class Product{
    string name;
    float price;
    string description;
    bool available;
    public:
    Product(string n , float p , string d, bool avail){
        this->available = avail;
        this->description = d;
        this->name = n;
        this->price = p;
    }

    Product(){

    }
    float getprice(){return price;}
    void display(){
        cout << name << ": " << price << endl;
    }
};

float partition(Product** products , int low , int high){
    float pivot = products[low]->getprice();
    int i = low;
    int j = high;

    while(i < j){
        while(i <= high && products[i]->getprice() <= pivot){
            i++;
        }
        while(j >= low && products[j]->getprice() > pivot){
            j--;
        }

        if(i < j){
            Product* temp = products[i];
            products[i] = products[j];
            products[j] = temp; 
        }
    }

    Product* temp1 = products[low];
    products[low] = products[j];
    products[j] = temp1;

    return j;
}

void quicksort(Product** products , int low , int high){
    if(low < high){
        float pivot = partition(products , low , high);
        quicksort(products ,low , pivot - 1);
        quicksort(products , pivot + 1 ,high);
    }
    return ;
}

int main(){
    int n =3;
    Product* products[3];
    products[0] = new Product {"Product 1" , 10.99 , "This is product 1",true};
    products[1] = new Product {"Product 2" , 5.99 , "This is product 2" ,false} ;
    products[2] = new Product {"Product 3" , 2.99 , "This is product 3" , true};

    cout << "Before Quick Sort: " << endl;
    for(int i = 0 ; i < n ; i++){
        products[i]->display();
    }
    quicksort(products , 0, n - 1);
    cout << "Product sorted by price: " << endl;
    for(int i = 0 ; i < n ; i++){
        products[i]->display();
    }

}