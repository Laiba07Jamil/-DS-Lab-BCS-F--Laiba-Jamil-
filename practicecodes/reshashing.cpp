#include <iostream>
using namespace std;

#define INITIAL_SIZE 15
#define PRIME 13   // prime < size

class StudentHashTable {
    string* name;
    int* roll_num;
    bool* occupied;

    int capacity;
    int count;

public:
    StudentHashTable() {
        capacity = INITIAL_SIZE;
        count = 0;

        name = new string[capacity];
        roll_num = new int[capacity];
        occupied = new bool[capacity];

        for(int i = 0; i < capacity; i++)
            occupied[i] = false;
    }

    int hash1(int key) {
        return key % capacity;
    }

    int hash2(int key) {
        return PRIME - (key % PRIME);
    }

    // ---------------- REHASHING FUNCTION ----------------
    void rehash() {
        cout << "\nRehashing... increasing size...\n";

        int oldCapacity = capacity;

        // find new capacity
        int newCapacity = nextPrime(capacity * 2);

        // create new temporary arrays
        string* newName = new string[newCapacity];
        int* newRoll = new int[newCapacity];
        bool* newOcc = new bool[newCapacity];

        for (int i = 0; i < newCapacity; i++)
            newOcc[i] = false;

        // store old table
        string* oldName = name;
        int* oldRoll = roll_num;
        bool* oldOcc = occupied;

        // update to new arrays
        name = newName;
        roll_num = newRoll;
        occupied = newOcc;
        capacity = newCapacity;
        count = 0;

        // reinsert all old elements
        for (int i = 0; i < oldCapacity; i++) {
            if (oldOcc[i]) {
                InsertRecord(oldRoll[i], oldName[i]);
            }
        }

        // free old arrays
        delete[] oldName;
        delete[] oldRoll;
        delete[] oldOcc;
    }

    // ---------------- PRIME CHECK ----------------
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    int nextPrime(int n) {
        while (!isPrime(n)) {
            n++;
        }
        return n;
    }

    // ---------------- INSERT ----------------
    void InsertRecord(int key, string n) {
    float loadFactor = (float)count / capacity;

    if (loadFactor > 0.75) {   // correct threshold
        rehash();
    }

    int index = hash1(key);
    int step = hash2(key);
    int start = index;
    int i = 0;

    while (occupied[index]) {
        if (roll_num[index] == key) {
            name[index] = n;
            return;
        }
        i++;
        index = (start + i * step) % capacity;

        if (index == start) {
            cout << "Table is full.\n";
            return;
        }
    }

    roll_num[index] = key;
    name[index] = n;
    occupied[index] = true;
    count++;
}


    // ---------------- SEARCH ----------------
    void SearchRecord(int num) {
        int index = hash1(num);
        int step = hash2(num);
        int start = index;
        int i = 0;

        while (occupied[index]) {
            if (roll_num[index] == num) {
                cout << "The student " << name[index]
                     << " has roll number " << num << endl << endl;
                return;
            }
            i++;
            index = (start + i * step) % capacity;

            if (index == start) break;
        }

        cout << "Roll number not found.\n\n";
    }

    // ---------------- TRAVERSE ----------------
    void traverse() {
        cout << "\nDisplaying Table (size = " << capacity << ")\n\n";

        for (int i = 0; i < capacity; i++) {
            if (!occupied[i]) continue;
            cout << "[" << i << "] (" << roll_num[i] << ", "
                 << name[i] << ")" << endl;
        }
        cout << endl;
    }
};

int main() {
    StudentHashTable students;

    students.InsertRecord(812, "Laiba");
    students.InsertRecord(688, "Simal");
    students.InsertRecord(852, "Armeen");
    students.InsertRecord(654, "Ariza");
    students.InsertRecord(827, "Maryam");
    students.InsertRecord(912, "Fatima");
    students.InsertRecord(1001, "Zara"); // will cause rehash

    students.traverse();

    cout << "Searching...\n";
    students.SearchRecord(852);

    cout << "Searching...\n";
    students.SearchRecord(345);
}
