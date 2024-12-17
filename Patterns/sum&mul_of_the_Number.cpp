#include<iostream>
using namespace std;

int main(void)
{
	int sum = 0;
	int mul = 1;
	int n;
	
	int count = -1;
	int i = 0;
	int k = 10;
	int store;
	int j;
	
	cout<<"Enter the Number "<<endl;
	cin>>n;
	int t = n;
	for(i=0 ; i<n ; i++)
	{
		t = t/n;
		count++;
		if(t==0)
		{
			
			for(j = 0 ; j<count ; j++)
			{
				k = k*10;
			
			}
		break;	
		}
		
	}
	//cout<<k;
	 while(k!=0)
	 {
		store = n/k;
		//cout<<store;
		sum = sum + store;
		mul = mul*store;
	   k =	k/10;
}
cout<<"sum"<<sum;
cout<<endl<<"Mul "<<mul;

return 0;
}
