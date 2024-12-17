#include<iostream>

using namespace std;

class student{
	public:
	
	string name;
	int rollNo;
	char grade;
	
	student(string n,int roll, char grade) : name(n) , rollNo(roll) , grade(grade){}  
	//Use Member Initilizer List to Intialize the Value
	void display()
	{
		cout<<"Name is "<<name<<endl;
		cout<<"Roll no is "<<rollNo<<endl;
		cout<<"Grade is "<<grade<<endl;
		}	
};

int main(void)
{
	student obj("Taha",559,'A');
	obj.display();
	
	return 0;
}
