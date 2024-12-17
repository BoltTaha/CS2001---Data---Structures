#include<iostream>
#include<string.h>
using namespace std;

bool Palindrome(char *ptr ,int length)
{
	  char *temp = ptr;
	  
	  int n = length - 1;
	  while(n!=0)
	  {
	  	temp++;
	  	n--;
	  }
	  //cout<<*ptr;
	  n = length/2;
	  //cout<<n;
	  int socket = 1;
	  while(n!=0)
	  {
	  	 if(*ptr!=*temp)
		  {
		  	socket = 0;
		  } 
		  
	  	if(*ptr==*temp)
	  	{
	  		ptr++;
	  		temp--;
		  }
        
		  n--;
		  
	  }
	  if(socket)
	  {
	  	return true;
	  }
	  else
	  {
	  	return false;
	  }
	  
}

int frequency(char *String,char s,int length)
{
	int i;
	int count = 0;
	for(i = 0;i<length ;i++)
	{
		if(String[i] == s)
		{
			 count++;
		}

	}
		return count;
}

int main(void)
{
	
	string Pal ;
	
	
	cout<<"Enter the String that youu want to Check"<<endl;
	getline(cin,Pal);
     
     
int length = Pal.length();
char String[length];
    int i;
    for(i = 0; i< length ; i++)
    {
    	String[i] = Pal[i];
	}
	if(Palindrome(String,length))
	{
		cout<<"Palindrome"<<endl;
	}
	else
	{
		cout<<"Not a Palindrome"<<endl;
	}
   
   cout<<"Enter the Character for Finding Frequency "<<endl;
   char s;
   cin>>s;
int Frequency = frequency(String, s, length);

   if(Frequency == 0)
   {
   	cout<<"Element is not present in the String "<<endl;
   	
   }
   else
   {
   	cout<<"The Frequency of "<<s<<" is "<<Frequency;
   }
	
	return 0;
}
