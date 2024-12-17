#include<iostream>

using namespace std;

class Teacher{
	
	public:
	string Name;
	string Subject;
	int Experince;	
	Teacher(string Name, string Subject , int experince)
	{
		this->Name = Name;
		this->Subject = Subject;
		this->Experince = experince;
	}	
	
};
class Principal : public Teacher
{
	public:
		int yearsAsPrincipal;
		
		  Principal(string Name, string Subject, int experience, int years)
        : Teacher(Name, Subject, experience), yearsAsPrincipal(years) {
        
    }
		
		void DisplayInfo()
		{
			cout<<"Name is "<<Name<<endl;
			cout<<"Subject "<<Subject<<endl;
			cout<<"experince"<<Experince<<endl;
			cout<<"Years as a Principle "<<yearsAsPrincipal<<endl;
			
			
		}
};

int main(void)
{
	Principal obj ("XYZ","ABC",10,5);
	obj.DisplayInfo();
}
