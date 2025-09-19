#include<iostream>
using namespace std;

	int sumOfN(int x, int n)
	
	{
		if(n==0)
		{
			return 1;
		}
		return  x*sumOfN(x,n-1);
	}
	
	int main()
	{
		int x,n;
		cout<<"Enter the number: ";
		cin>>x;
		cout<<"Enter the power: ";
		cin>>n;
		cout<<"power: "<<sumOfN(x,n);
	}
