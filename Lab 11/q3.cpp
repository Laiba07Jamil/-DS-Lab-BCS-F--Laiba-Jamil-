#include <iostream>
#include <list>
using namespace std;

#define TABLE_SIZE 100

class Hash{
    list<pair<string,string>> table[TABLE_SIZE];

    int hashfunction(string key){
        int sum = 0 ;
        for(char c : key){
            sum += int(c);
        }
        return sum % TABLE_SIZE;
    }

    public:

    void insert(string key , string value){
        int index = hashfunction(key);
        for(auto &p : table[index]){
            if(p.first == key){
                p.second = value;
                return ;
            }
        }
        table[index].push_back({key,value});
    }

    void search(string key){
        int index = hashfunction(key);

        for(auto &p : table[index]){
            if(p.first == key){
                cout << "search for " << p.first << " : " << p.second << endl;
                return;
            }
        }
        cout << "Word not found. "<< endl;
    }

    void remove(string key){
        int index = hashfunction(key);

        for(auto p = table[index].begin(); p != table[index].end() ; p++){
            if(p->first == key){
                table[index].erase(p);
                cout << "key " << p->first << " deleted successfully." << endl;
                return;
            }
        }
        cout << "Key not found." << endl;
    }

    void traverse() {
    for (int i = 0; i < TABLE_SIZE; i++) {

        if (table[i].empty())
            continue;

        cout << "[" << i << "] ";

        auto it = table[i].begin();

        while (it != table[i].end()) {
            cout << "(" << it->first << "," << it->second << ")";
            auto nextit = it;
            nextit++;
            if (nextit != table[i].end()){
                cout << " -> ";
            }
            it++;
        }
        cout << endl;
    }
}

};

int main(){
    Hash table;
    table.insert("AB" ,"FASTNU");
    table.insert("CD" , "CS");
    table.insert("ABC" , "UNI");
    table.insert("ABd" , "KHI");
    table.insert("b" , "aplha");
    table.traverse();
    cout << endl;
    cout << "Searching for key " << endl;
    table.search("ABd");
    cout << endl;
    table.remove("b");
    cout << endl;
    table.traverse();
    return 0;


}