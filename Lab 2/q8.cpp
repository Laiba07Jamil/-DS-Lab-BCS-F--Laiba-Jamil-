#include <iostream>
using namespace std;

int main(){
    int n,m;
    cout << "Enter the days for reading temperature: " ;
    cin >> n;
    cout << "Enter the times(m) : ";
    cin >> m;

    float **temperatures = new float* [n];
    for(int i = 0 ; i < n ; i++){
        temperatures[i] = new float[m];
    }

     for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << "Enter the temperature for [" << i+1 << "][" << j+1 << "]: ";
            cin >> temperatures[i][j] ;
        }
    }
    
    cout << "----Temperature Readings----" << endl;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout << temperatures[i][j] << " ";
        }
        cout << endl;
    }

    float maxDay = -1;
    int Hotday = 0;
    float minDay = 9999;
    int coldday = 0;
    for(int i = 0 ; i < n ; i++){
        float sum = 0 ;
        for(int j = 0 ; j < m ; j++){
            sum += temperatures[i][j];
        }
        float average = sum / m ;
        cout << "The average of day " << i+1 << " is : " << average << endl;
        if(average > maxDay){
                maxDay = average;
                Hotday = i+1;
            }
        if(average < minDay){
                minDay = average;
                coldday = i+1;
            }
    }
    cout << "The Hottest Day is " << Hotday << " with temperature " << maxDay << endl;
    cout << "The Coldest Day is " << coldday << " with temperature " << minDay << endl;


    for(int i = 0 ; i < n ; i++){
        delete[] temperatures[i];
    }
    delete[] temperatures;
    return 0 ;

}