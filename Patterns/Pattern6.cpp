#include<iostream>
using namespace std;

int main(void)
{   
    int n;
    
	cout<<"Enter the size for the rows and col "<<endl;
	cin>>n;
	
	int  i =1;
	
	while(i<=n)
	{
		int  j = 1;
		char Alp = 'A';
		while(j<=n)
		{
			cout<<Alp<<" ";
			Alp++;
			j++;
		}
		cout<<endl;
		 i++;
	}
}
