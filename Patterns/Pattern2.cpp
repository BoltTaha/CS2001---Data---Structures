#include<iostream>

using namespace std;

int main(void)
{   
    int n;
	
	cout<<"Enter the size of your Pattern in the form of Row X Columns "<<endl;
	cin>>n;
	int count = 1;
	
	int i = 1;
	
	while(i<=n)
	{    
	    int j = 1;
	    while(j<=i)
	    {
	    	cout<<count++<<" ";
	    	
	    	j++;
		}
		
		cout<<endl;
		i++;
	}
	
	return 0;
}
