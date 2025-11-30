#include <iostream>
#include <string>
using namespace std;

#define d 256  

void rabinKarp(string text, string pattern, int q) {
    int n = text.length();  
    int m = pattern.length();
    int result[100];
    int count = 0;
    int collisions[100];
    int colcount = 0;

    if (m == 0 || m > n) {
        cout << "No valid pattern to search.\n";
        return;
    }

    int p = 0;  
    int t = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {

        if (p == t) {
            bool match = true;
            for (int j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                result[count] = i;
                count++;
            }
            else{
                collisions[colcount] = i;
                colcount++ ;
            }
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = t + q;
        }
    }

    if(colcount > 0){
        cout << "Collisions occur at window : [" ;
        for(int i = 0 ; i < colcount ; i++){
            cout << collisions[i] << " ";
        }
        cout << "]" << endl;
        cout << "\n(These were discarded)\n\n";
    }

    cout << "Output: [";
    for(int i = 0 ; i < count ; i++){
        cout << result[i] << " ";
    }
    cout << "]" << endl;
}

int main() {
    string text = "Data structures and Algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    int q = 101; 

    rabinKarp(text, pattern, q);

    return 0;
}
