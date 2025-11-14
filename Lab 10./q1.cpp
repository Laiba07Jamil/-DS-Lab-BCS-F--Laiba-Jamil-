#include<iostream>
using namespace std;

#define MAX 100
class Heap{
    int heap[MAX];
    int size;

    int parent(int i){return (i-1)/2;}
    int leftchild(int i){return 2 * i + 1;}
    int rightchild(int i){return 2 * i * + 2;}

    void swap(int a ,int b){
        int temp = a;
        a = b;
        b = temp;
    }
    public:
    Heap(){
        size = 0;
    }

    void heapify_up(int i){
        while(i != 0 && heap[i] > heap[parent(i)]){
            swap(heap[i] , heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify_down(int i){
        int largest = i;
        int l = leftchild(i);
        int r = rightchild(i);

        if(l < size && heap[l] > heap[largest]){
            largest = l;
        }
        if(r < size && heap[r] > heap[largest]){
            largest = r;
        }

        if(i != largest){
            swap(heap[i] , heap[largest]);
            heapify_down(largest);
        }
    }

    void insert(int val){
        if(size == MAX){
            cout << "Heap Overflow!" << endl;
            return ;
        }
        heap[size] = val;
        heapify_up(size);
        size++;
    }

    void update(int i , int new_val){
        if(i >= size){
            return;
        }
        int temp = heap[i];
        heap[i] = new_val;
        if(new_val > temp){
            heapify_up(i);
        }
        else{
            heapify_down(i);
        }
        
    }
    
    void delete_max(){
        if(size == 0){
            return ;
        }
        heap[0] = heap[size - 1];
        size --;
        heapify_down(0);
    }
    
    void display(){
        if(size == 0){
            return ;
        }
        for(int i = 0 ; i < size ; i++){
            cout << heap[i] << " ";
        }
    }

};

int main(){
    Heap h;
    h.insert(8);
    h.insert(7);
    h.insert(6);
    h.insert(5);
    h.insert(4);
    
    cout << "Initial heap:" << endl;
    h.display();
    cout << endl;
    h.update(3,10);
    cout << "Heap after update: " << endl;
    h.display();
    h.delete_max();
    cout << endl;
    cout << "After deleteion: " << endl;
    h.display();
}
