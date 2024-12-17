#include<iostream>

using namespace std;

int main(void)
{
	int n;
	  int row = 1;
     int check = 0;
     int check2 = 0;
     int count = 1;
     int  i = 0;
	int hold = 0;
	cout<<"Enter the Number of rows and columns "<<endl;
	cin>>n;
	
   
     
     while(row<=n)
     {
     int col = 1;
	 while(col<=row)
	 {
	 	if(count==1)
	 	{
	 		cout<<count;
	 		count++;
	 		col++;
	 		continue;
		 }
	else
	{   
		cout<<count<<" ";
		if(hold>=count)
		{
			check2 = -1;
		}
		
	if(count % 2 != 0 && check2 == 0)
	{    
	    hold = count;
		check++;
	for(i = 0 ; i < check ; i++)
	{
		count--;
		}	
		
	}	
		 check2 = 0;}	
		count++;
		col++;  
		 }	
		cout<<endl;
		row++; 
	 }
	return 0;
}
