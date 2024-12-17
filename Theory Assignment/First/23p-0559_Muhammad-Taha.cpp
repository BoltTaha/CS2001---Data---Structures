#include<iostream>

//const int ARRAY_SIZE = 10;
using namespace std;


class List{
	public:
	
	
	int *store;
	int *current_pointer;
	
	 
    int List_Element = 0;	
    const int ARRAY_SIZE = 10;
	
  bool IsFull();
  bool IsEmpty();
  int listSize();
  int maxListSize();
  int get(int);
  bool update(int,int);
  int length();
  int* start();
  int* end();
  bool back();
  bool next();
  bool Add(int,int);
  bool remove(int);
  bool clear_list();
  void operator = (List&);
  void print();
  
  	
 List()
 {   
 	store = new int[ARRAY_SIZE];
 	current_pointer = store;
 }

 ~List()
 {
	delete[] store;
 }
	
	
};

   bool List:: IsFull(){
	    if(List_Element == ARRAY_SIZE)
	    {
	    	return true;
		}
		return false;
	    
   }
    bool List:: IsEmpty()
    {
    	 if(List_Element == 0)
	    {
	    	return true;
		}
		return false;
	    
	}
	
	int List :: listSize()
	{
		return List_Element;
	}
	
	int List::maxListSize()
	{
		return ARRAY_SIZE;
		
	}
	
	int List::get(int position)
	{
	   if(position>=List_Element || position < 0)
	   {
	   	return -1;
	   }

       current_pointer = start() + position;
       
	   return *current_pointer;
	   
	}
	
	 bool List::update(int replace, int position)
	 {
	 	
	   if(position>=List_Element || position < 0)
	   {
	   	return 0;   
	   }

       current_pointer = start() + position;
       *current_pointer = replace;
	   return 1;
	 }
	
	int List:: length(){
		return List_Element;
	}
	
	int* List::start()
	{   
		current_pointer = store;
		return current_pointer;
		
	}
	
	int* List::end()
	{   
		if(List_Element == 0)
    {
        return store; 
    }
		
		return store + List_Element - 1;
		
	}
	bool List::back()
	{   
	     if(current_pointer == store)
	     {
	     	return false;
		 }
		current_pointer--;
		
		return true;
	}
	
	bool List::next(){
		if(current_pointer == end())
		{
			return false;
		}
		  current_pointer++;
		  return true;
	}
	
	bool List::clear_list()
	{   
	if(store != NULL)
	{   
	    delete [] store;
	    
	    store = new int[ARRAY_SIZE];
	    current_pointer = store;
		List_Element = 0;
       return true;
	}
		return false;
		
	}
	
bool List::Add(int pos,int value)
{
	if(pos > List_Element || pos < 0  || List_Element >= ARRAY_SIZE)
	{
		return false;
	}
	
	if(pos==List_Element)
	{
		current_pointer = store + List_Element ;
		*current_pointer = value;
		List_Element++;
	//	cout<<"this";
		return true;
	}
	current_pointer = start() + pos;
	int *temp0 = end(); 
    int *temp1 = temp0 + 1;
    int *temp2 = temp0;
    while(temp2 >= current_pointer )
	{
		*temp1 = *temp2;
		temp1--;
		temp2--;
	 } 
	 *current_pointer = value;
	List_Element++;
	return true;
	
}
 
 bool List::remove(int pos)
 {
 	if( pos < 0 || pos >= List_Element)
	{
		return false;
	}
	int *temp1 = start() + pos;
	int *temp2 = start() + List_Element - 1;
	   while (temp1 < temp2)
    {
        *temp1 = *(temp1 + 1);
        temp1++;
    }
	 List_Element--;
	 return true;
 }
	void List::operator = (List &obj)
	{
		   if (this == &obj) {
        return; 
    }
		delete[] store;
		
		store = new int[ARRAY_SIZE];
		
		List_Element = obj.List_Element;
		int n = List_Element;
		
		int* current_pointer = store; 
        int* obj_pointer = obj.store;
		while(n != 0)
		{
			*current_pointer++ = *obj_pointer++;
			n--;
			
		}
		
	}

	void List::print()
	{   
	int *temp = start();
	cout<<endl;
	int count = List_Element;
	if(count==0)
	{
		cout<<"No Data "<<endl;
		
	}

		while(count> 0)
		{
			cout<<*temp++<<"  ";
			count --;
			
		}
		cout<<endl;
	}
		
int main(void)
{   
     int n;

	List obj1;
	
	do{
	cout << " 1. Add()" << endl;
	cout << " 2. Remove()" << endl;
	cout << " 3. clearList()" << endl;
	cout << " 4. start()" << endl;
	cout << " 5. end()" << endl;
	cout << " 6. back()" << endl;
	cout << " 7. Next()" << endl;
	cout << " 8. update()" << endl;
	cout << " 9. listSize()" << endl;
	cout << "10. maxListSize()" << endl;
	cout << "11. IsFull()" << endl;
	cout << "12. IsEmpty()" << endl;
	cout << "13. get()" << endl;
	cout << "14. operator=()" << endl;
	cout << "15. length()" << endl;
    cout<<" 16. Print"<<endl;
    cout<<" 17. Exit"<<endl;
    cout<<" Enter your choice:"<<endl;
    cin>>n;
    if(n==1)
    { 
        int data;
        int pos;
    	cout<<"Enter the Data that you want to Add "<<endl;
    	cin>>data;
    	cout<<"Enter the Postion on which you want to add "<<data<<endl;
    	cin>>pos;
    	
    	if(obj1.Add(pos,data))
		{
			cout<<"Data is Succesfully Added "<<endl;
		}
		else
		{
			cout<<"The data could not be added because the list or array is full or the position is not in sequential order"<<endl;
		}
	}
	else if(n==2)
	{   int n;
		cout<<"Enter the position from where you want to Remove Data "<<endl;
		
		cin>>n;
		if(obj1.remove(n))
		{
			cout<<"The Element is Successfully Remove from the List "<<endl;
		}
		else{
			cout<<"The Element is not found in the List "<<endl;
		}
	}
	
	else if(n==3)
	{
		if(obj1.clear_list())
		{
			cout<<"The List is Clear SuccessFully"<<endl;
			
		}
		else{
			cout<<"The list is Not clear Successfully"<<endl;
		}
	}
	
	else if(n==4)
	{
		cout<<"Element at Start is "<<*obj1.start()<<endl;
	}
	
	else if(n==5)
	{
		cout<<"Element at End is "<<*obj1.end()<<endl;
	}
	
	else if(n==6)
	{
		if(obj1.back()){
			cout<<"The current pointer has successfully moved back."<<endl;
		}
		else
		{
			cout<<"The current pointer is unable to move backward."<<endl;
		}
	}
	
	else if(n==7)
	{
		if(obj1.next())
		{
			cout<<"The current pointer has Successfully move FOrward,"<<endl;
		}
		else
		{
			cout<<"The Current Pointer is unable to move Forward, "<<endl;
		}
	}
	
	else if(n==8)
	{
		cout<<"Enter the Number which you want to Replace. "<<endl;
		int replace;
		int pos;
		cin>>replace;
		cout<<"ENter the Pos where you want to Replace the Number. "<<endl;
		cin>>pos;
		
		if(obj1.update(replace,pos))
		{
			cout<<"The Number is SuccFully Replaced. "<<endl;
		}
		else
		{
			cout<<"The Number does not Successfully replaced. "<<endl;
		}
	}
	
	else if(n==9)
	{
		cout<<"The List Size is "<<obj1.listSize()<<endl;
	}
	
	else if(n==10)
	{
		cout<<"The Max List Size is " <<obj1.maxListSize()<<endl;
	}
	
	else if(n==11)
	{
		if(obj1.IsFull())
		{
			cout<<"The List is Full "<<endl;
		}
		else
		{
			cout<<"The List is not Full. "<<endl;
		}
	}
	
	else if(n==12)
	{
		if(obj1.IsEmpty())
		{
			cout<<"The List is Empty "<<endl;
		}
		else
		{
			cout<<"The List is not Empty "<<endl;
		}
	}
	
	else if(n==13)
	{
		cout<<"Enter the Position from where you want to geta a value "<<endl;
		int pos;
		cin>>pos;
		int k = obj1.get(pos);
		if(k==-1)
		{
			cout<<"Pos is Greater than the size of List "<<endl;
		}
		else
		{
		
		cout<<"The Value is "<<k<<endl;
	}
	}
	
	else if(n==14)
	{
		cout<<"Operator OverLoading is Done "<<endl;
		List obj2 = obj1;
		
	}
	
	else if(n==15)
	{
		cout<<"The Length is "<<obj1.length()<<endl;
																	
	}
	else if(n==16)
	{   cout<<"Elements are "<<endl;
		obj1.print();
	}
	else{
		exit(0);
	}
	
	
    
	}while(n>=1 && n<=16);
	
	
	
	return 0;
}
