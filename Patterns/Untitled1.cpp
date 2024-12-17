#include<iostream>
//FInd the sum of even number upto N
using namespace std;

int main(void)
{
	cout<<"Enter an Number";
	int n;
	int sum  = 0;
	cin>>n;
	int i =1;
	
	while(i<=n)
	{
		if(i%2==0)
		{
			sum = sum + i;
		}
		i++;
	}
	cout<<"The sum is "<<sum;
}
