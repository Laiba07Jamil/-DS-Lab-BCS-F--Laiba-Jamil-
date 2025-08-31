#include <iostream>
using namespace std;

class Book{
    int id;
    public:
    Book(int id){
        this->id = id;
    }
    Book(){}

    int getid(){
        return id;
    }
    void setID(int ID){
        this->id = ID;
    }

    void display(){
        cout << "ID: " << id << endl;
    }
};

class Category{
    string name;
    int bookcount;
    Book *books;
    public:
    Category() {}
    Category(int count , string n){
        name = n;
        bookcount = count;
        books = new Book[bookcount];
    }

    string getname(){
        return name;
    }

    void input(){
        for(int i = 0 ; i < bookcount ; i++){
            int ID;
            cout << "Enter ID for " << name << " category book " << i + 1 << ": " ;
            cin >>  ID;
            books[i].setID(ID);
        }
    }

    void display(){
        cout << "\nCategory: " << name << " -> ";
        for(int i = 0 ; i < bookcount ; i++){
            cout << books[i].getid() << " ";
        }
        cout << endl;
    }

    bool search(int id){
        for(int i = 0 ; i < bookcount ; i++){
            if(books[i].getid() == id){
                cout << "Book Found in " << name << endl;
                return true;
            }
        }
        return false;
    }

    ~Category(){
        delete[] books;
    }
};

class Library{
    int categorycount;
    Category *category;

    public:
    Library(int n){
        categorycount = n ;
        category = new Category[categorycount];
    }

    void setcategory(int *bookcount , string* name){
        for(int i = 0 ; i < categorycount ; i++){
            category[i] = Category(bookcount[i] , name[i]);
            cout << "\nCategory " << i+1 << ":\n";
            category[i].input();
        }
    }

    void display(){
        for(int i = 0 ; i < categorycount ; i++){
            category[i].display() ;
        }
    }

    void searchBook(){
        int id;
        cout << "Enter the ID to search :";
        cin >> id;
        bool flag = false;
        for(int i = 0 ; i < categorycount ; i++){
            if(category[i].search(id)) {
                flag = true;
            }
            else flag = false;
        }
    }

    ~Library(){
        delete[] category;
    }  
};

int main(){
    int rows;
    cout << "Enter rows for category: " ;
    cin >> rows;
    int *count = new int[rows];
    for(int i = 0 ; i < rows ; i++){
        cout << "Enter number of books in each category: " ;
        cin >> count[i];
    }
    string *names = new string[rows];
    for(int i = 0 ; i < rows ; i++){
        cout << "Enter names of category: " ;
        cin >> names[i];
    }
    Library l1(rows);
    l1.setcategory(count , names);
    l1.searchBook();
    l1.display();

    delete[] names;
    delete[] count;
    return 0 ;
}