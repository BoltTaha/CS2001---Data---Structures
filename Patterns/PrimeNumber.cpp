#include<iostream>
using namespace std;
int main(void)
{
	int i;
	int n;
	int tmp = 0;
	int temp = 0;
	
	cout<<"Enter the Number that you want to check : "<<endl;
	cin>>n;
	
	for(i = 1 ; i <= n ; i++)
	{
		if(n%i!=0)
		{
			tmp++;
			{
				if(tmp>=2)
				{
					cout<<"Prime Number"<<endl;
					break;
				}
			}
		}
		else
		{
			temp++;
			{
				if(temp>=2)
				{
					cout<<"Not a Prime Number"<<endl;
					break;
				}
			}
		}
	}
}
