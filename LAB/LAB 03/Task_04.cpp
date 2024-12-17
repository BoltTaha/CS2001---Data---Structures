#include<iostream>

using namespace std;

class Student{
  
  public:
  string name;
  int age;

  Student()
  {
 
  }
//   Student(string name,int age)
//   {
//     this-> name = name;
//     this-> age = age;
//   }
  void setname(string nam)
  {
    name = nam;
  }

  void setage(int ag)
  {
    age = ag;
  }
  void print()
  {
    cout<<"The Name of the Student is "<<name<<endl;
    cout<<"The age of the Student is "<<age;
  }



};

int main(void)
{ 
   // cout<<"Enter the Size of Student List "<<endl;
    int n  = 3;
    //cin>>n;
   Student *obj = new Student[n];
    string name;
    int age;
    for(int i = 0;i<n;i++)
    {
        cout<<"Enter the name of the student "<<endl;
        getline(cin,name);
        cout<<"Enter the age of the Student "<<endl;
        cin>>age;
        obj[i].setage(age);
        obj[i].setname(name);
        cin.ignore();
    }

    for(int i = 0 ; i<n;i++)
    {
        obj[i].print();
        cout<<endl;
    }

    delete [] obj;

    return 0;
}