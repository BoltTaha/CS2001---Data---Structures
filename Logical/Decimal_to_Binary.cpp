#include<iostream>
using namespace std;

int main(void)
{
	int n;
	int i = 0;
	int arr[i];
	
	cout<<"Enter the Number in Decimal "<<endl;
	cin>>n;
	
	int k  = n;
	
	while(n!=0)
	{
		arr[i] = n % 2;
		
		
		k = k / 2;
		n = k;
		i++;
	}
    int j;
    int new_arr[i];
    for(j = 0 ; j < i-1 ; j++)
    {
    	new_arr[j] = arr[i-j-1];
	}
	for(j = 0 ; j < i ; j++)
	{
		cout<<new_arr[j];
	}
}
