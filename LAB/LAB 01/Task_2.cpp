#include<iostream>

using namespace std;



class student{
	public:
	
	string name;
	int rollNo;
	char grade;
	
	student(string n,int roll, char grade = 'U') : name(n) , rollNo(roll) , grade(grade){}
	
	void display()
	{
		cout<<"Name is "<<name<<endl;
		cout<<"Roll no is "<<rollNo<<endl;
		cout<<"Grade is "<<grade<<endl;
	}	
	void setGrade(char grade)
	{
	      this->grade = grade;
	}
};

int main(void)
{
	student obj("Taha",559);
	char grade;
	cout<<"Modify the Grade of the Student"<<endl;
	cin>>grade;
	
	obj.setGrade(grade);
	
	obj.display();
	
	return 0;
}
