#include<iostream>
#include <cstdlib>
#include <ctime>   
using namespace std;

int random()
{

	return 10 + rand() % 21;
}
int main(void)
{      srand(time(NULL));
      int (*ptr)[7];
     
     string days[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
      
      int arr[4][7];
      
      ptr = arr;
      
      
      
      for(int i=0 ; i < 4*7 ; i++ )
      {
      	(*ptr)[i] =  random();
	  }
     
	 
	    for (int i = 0; i < 4 * 7; ++i) {
	    	
	    	cout<<(*ptr)[i]<<" ";
			if(i%7==6)
			{
				cout<<endl;
			 } 
	    	
	    }
	 int count = 1;  
	 int max = (*ptr)[0]; 
	 string temp;
	 int track = 0;
	  for (int i = 0; i < 4 * 7 ; ++i) {
	    	
	    		if(max < (*ptr)[i] )
	    	{
	    		max = (*ptr)[i];

           track = i % 7;
			}
			
			if(i%7==6)
			{
				cout<<"Hotest Day of Week: "<<count<<" is "<<days[track]<<" Having a Temperature: "<<max<<endl;
				max = 0;
				count++;

			 } 
	    	
	    }  
	
	return 0;

}
