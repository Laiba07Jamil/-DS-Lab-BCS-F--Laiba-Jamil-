#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string Text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";

    int n = Text.length();
    int m = pattern.length();
    int comparision = 0;
    int result[200] ;
    int count = 0;

    for(int i = 0 ; i < n - m ; i++){
        int j = 0 ;
        while(j < m && Text[i+j] == pattern[j]){
             comparision++ ;
               j++;
             if(j == m){
                result[count] = i;
                count++;
             }
        }
    }

    cout << "Output: [";
    for(int i = 0 ; i < count ; i++){
        cout << result[i] << " ";
    }
    cout << "]" << endl;
    cout << "Comparisions: " << comparision;
}