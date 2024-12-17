#include<iostream>

using namespace std;

int main(void)
{   
	int i = 1;
	char cont = 'A';
	int n;
	cout<<"Enter the Number of rows and columns "<<endl;
	cin>>n;
	while(i<=n)
	{
		int j = 1;
	while(j<=n)
	{
		cout<<cont;
		j++;
		}
	cont++;
	i++;
	cout<<endl;	
			
	}
}
