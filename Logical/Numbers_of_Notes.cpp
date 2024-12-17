#include<iostream>
using namespace std;

int main(void)
{
	int n;
	cout<<"Enter the AMount of Ruppess"<<endl;
	cin>>n;
	int m = n;
	int hundreds,fifty,twenty,ones;
	 cout<<"The Number of Notes in amount of "<<n<<" are Following "<<endl;
	 while(m!=0)
	 {
	    if(m>=100)
	    {
	    	
			hundreds = n / 100;
	    	m = m - 100*hundreds;
	    	n = m;
		}
		else if(m>=50)
		{
			fifty = n / 50;
	    	m = m - 50*fifty;
	    	n = m;
		}
		else if(m>=20)
		{
			twenty = n / 20;
	    	m = m - 20*twenty;
	    	n = m;
		}
		else{
			ones = n / 1;
	    	m = m - 1*ones;
	    	n = m;
		}
     }
     
     cout<<"Hundreds "<<hundreds<<endl;
     cout<<"Fifty "<<fifty<<endl;
     cout<<"Twenty "<<twenty<<endl;
     cout<<"Ones "<<ones<<endl;
}
