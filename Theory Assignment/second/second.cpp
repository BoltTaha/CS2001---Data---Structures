#include<iostream>
#include<random>

using namespace std;
 
 random_device rd;    // Seed the generator only once globally
 mt19937 gen(rd());   // Mersenne Twister generator seeded with rd()

unsigned int Random()   
{
   
   uniform_int_distribution<int> dist(0, 65535);    // Generate a random number within the specified range
    return dist(gen);     // Use the global generator without reseeding
}

/*Since we are limited to using only two libraries, and generating random numbers using the
    standard `rand()` and `srand()` functions from `<ctime>` would require an additional header file,
    we will avoid using these functions. Instead, we can implement a simple custom random number
    generation technique.*/

class PCB
{
    public:
    int processID;
    string processState;
    int priority;
    unsigned int stackAddress;
    unsigned int heapAddress;
    //IN HEXA 
    string Stack_Address;
    string Heap_Address;
    PCB* next;
    int Creator_ID;         //use to track the Child processes
                                                                             // (assuming 0 indicates no parent)
    PCB(int id, string state, int prio, unsigned int stack, unsigned int heap,int track_child = 0 )
    {
          this->processID = id;
          this->processState = state;
          this->priority = prio;
          this->stackAddress = stack;
          this->heapAddress = heap;
          this->Creator_ID = track_child;         //this is use to track the child process if this is equal to zero so it's means it is a parent process,else it is a child process
          next = NULL;
          stackAddress = stack;
          heapAddress = heap;
          Stack_Address = genrate_address_in_hexa(stackAddress);
          Heap_Address = genrate_address_in_hexa(heapAddress);

    }

   string genrate_address_in_hexa(unsigned int random)
   {
    
    string address = "0x0000";
    if(random == 0)
    {
       return address;
    }
    int cnt = 5;
    int remainder;
    int hold;
    while(random != 0)
    {  
        hold = random;
         random = random / 16;
         remainder = hold - (random * 16);

        if(remainder > 9)
        {
            if(remainder == 10)
            {
                address[cnt] = 'A';
            }

            else if(remainder == 11)
            {
                address[cnt] = 'B';
            }

            else if(remainder == 12)
            {
                address[cnt] = 'C';
            }

            else if(remainder == 13)
            {
                address[cnt] = 'D';
            }

            else if(remainder == 14)
            {
                address[cnt] = 'E';
            }

             else //if(remainder == 15)
            {
                address[cnt] = 'F';
            }
           
        }
        else
        {  string store = to_string(remainder);
            address[cnt] = store[0];
        }
        cnt--;
    }
    return address;
   }

};

class PCB_Manager{
   public:
   PCB* Head_process;
   int unique_process_id;

   PCB_Manager()
   {
      Head_process = NULL;
      unique_process_id = 100;      //By default the process id
   }
   void Add_new_Process()
   {
    int choice;
    string state;
      cout<<"The Process ID for new Process is "<<unique_process_id<<endl;
    
    do {
        cout << "Enter the Process state." << endl;
        cout << "1. Ready." << endl;
        cout << "2. Running." << endl;
        cout << "3. Waiting." << endl;
        cout << "4. New." << endl;
        cout << "Enter the Choice (1-4): ";
        
        cin >> choice; 

        if (choice < 1 || choice > 4) 
        {
         cout<<"Invalid choice. Please enter a number between 1 and 4."<<endl;
        }
        
    }while(choice < 1 || choice > 4); 
      
      if(choice == 1)
      {
        state = "Ready";
      }
      else if (choice == 2)
      {
       state = "Running";

      }
      else if (choice == 3)
      {
        state = "Waiting";
      }
      else
      {
        state = "New";
      }
       cout<<"You selected "<<state<<" as your State of Process."<<endl;

      int set_priority;
      cout<<"Enter the priority level (please Select Wisely According to your Number of Processes)"<<endl;
      cin>>set_priority;

      unsigned int Stack_address = Random();
      unsigned int Heap_address = Random();
      
      PCB* newpcb = new PCB(unique_process_id,state,set_priority,Stack_address,Heap_address);
      ++unique_process_id;
      if(Head_process == NULL)      //when there is no process 
      {
        Head_process = newpcb;
        return;
      }
      PCB* temp = Head_process;
      while(temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = newpcb;
   }

   void remove_process_by_process_id(int process_id)
   {
    PCB* temp;
    if(Head_process == NULL)
    {
        cout<<"There is no Process is Currently Processing "<<endl;
        return;
    }

    if(Head_process->processID == process_id)
    {
         temp = Head_process;
        Head_process = Head_process->next; 
        delete temp; 
        cout<<"Process with ID "<<process_id<<" has been removed."<<endl;
        return ;
    }
    

     temp = Head_process;
    while(temp->next != NULL && temp->next->processID != process_id )
    {
        temp = temp->next;
    }
    if(temp->next == NULL)
    {
        cout<<"Please enter the correct Process id that you want to delete "<<endl;
        return;
    }
    PCB* link = temp->next;
    temp->next = link->next;

    delete link;
     cout<<"Process with ID "<<process_id<<" has been removed."<<endl;

}

  void Kill_all_process()
  {
    if(Head_process == NULL)
    {
        cout<<"No Process is currently Processing "<<endl;
        return;
    }
      PCB* temp ;
      while(Head_process != NULL)
      {
        temp = Head_process;
        Head_process = Head_process->next;
        delete temp;
      }
    temp = NULL;
    Head_process = NULL;
    cout<<"All processes have been terminatd "<<endl;
  }
   
   void Kill_parent_process(int process_id) 
   {
    if(Head_process == NULL)
     {
        cout << "There is no Process Currently Processing." << endl;
        return;
    }

    if(Head_process->processID == process_id) 
    {
        PCB* temp = Head_process;
        Head_process = Head_process->next; 
        cout << "Terminated parent process with ID: " << temp->processID << endl; 
        delete temp;

        Kill_child_processes(process_id);
        return;
    }

    PCB* temp = Head_process; 
    while(temp != NULL && temp->next != NULL) 
    {
        if(temp->next->processID == process_id)
         {
            PCB* link = temp->next;
            temp->next = link->next;
            cout << "Terminated parent process with ID: " << link->processID << endl; 
            delete link;

            Kill_child_processes(process_id);
            return;
        }
        temp = temp->next; 
    }
    cout << "No process found with ID: " << process_id << endl; 
}

void Kill_child_processes(int parent_id)
{
    PCB* temp = Head_process;
    PCB* prev = NULL; 
    bool checkChild = false;

    while(temp != NULL) 
    {
        if(temp->Creator_ID == parent_id) 
        {   checkChild = true;
            PCB* link = temp;
            if(prev == NULL) 
            {
                Head_process = temp->next;
            } 
            else 
            {
                prev->next = temp->next;
            }
            cout<<"Terminated child process with ID: "<<link->processID<<endl; 
            temp = temp->next; 
            delete link; 
        } 
        else 
        {
            prev = temp; 
            temp = temp->next;
        }
       
    }
     if(checkChild == false)
        {
           cout<<"There is no Child Process for the Process ID"<<endl<<endl;
        }
}

  int GetParentId(int id)
   {
    if(Head_process == NULL) 
    {
        cout<<"No processes are currently running."<<endl;
        return -1; 
    }

    PCB* temp = Head_process;

    while(temp != NULL)
     {
        if(temp->processID == id) 
        {
            return temp->Creator_ID; 
        }
        temp = temp->next;
    }

    cout<<"Process with ID " <<id<< " not found."<<endl;
    return -1; 
 }

  int* GetChildIds(int processId, int &size) 
  {
    size = 0;
     if(Head_process == NULL) 
    {
        cout<<"No processes are currently running."<<endl;
        return NULL; 
    }

    PCB* temp = Head_process;
    while(temp != NULL) 
    {
        if(temp->Creator_ID == processId) 
        {
            size++;
        }
        temp = temp->next;
    }

    if(size == 0) 
    {
        cout << "No child processes found for process ID " << processId << "." << endl;
        return NULL;
    }

    int* childProcessIds = new int[size];
    int index = 0;

    temp = Head_process;
    while(temp != NULL)
     {
        if (temp->Creator_ID == processId) 
        {
            childProcessIds[index++] = temp->processID;
        }
        temp = temp->next;
    }

    return childProcessIds;
 }

  void fork(int processid)
  {
     if(Head_process == NULL) 
    {
        cout<<"No processes are currently running."<<endl;
        return; 
    }
    PCB* temp = Head_process;

    while(temp != NULL && temp->processID != processid)
    {
        temp = temp->next;
    }

    if(temp == NULL)
    {
        cout<<"There is No process is Running with this Process id."<<endl;
        return;
    }

      unsigned int Stack_address = Random();
      unsigned int Heap_address = Random();

    PCB* newpcb = new PCB(unique_process_id,temp->processState,temp->priority,Stack_address,Heap_address,temp->processID);
   
    temp = Head_process;
    while(temp->next != NULL)
    {
        temp = temp->next;

    }
    temp->next = newpcb;

    cout<<"The child Process is Created."<<endl;
           unique_process_id++;
  }

     void print()
     {
        PCB* temp = Head_process;
        if(temp == NULL)
        {
            cout<<"There is no process is Currently Running."<<endl;
            return;
        }
         cout<<"Process ID: "<<"Process State: "<<" Priority: "<<" Stack Address "<<" Heap Address "<<" Creator ID (0 Represent it is a Parent Process) "<<endl;
        while(temp != NULL)
        {
           cout<<"  "<<temp->processID<<"           "<<temp->processState<<"         "<<temp->priority<<"               "<<temp->Stack_Address<<"        "<<temp->Heap_Address<<"       "<<temp->Creator_ID<<"   "<<endl;
           temp = temp->next;
        }
        cout<<endl;
     }



};

int main(void)
{

  PCB_Manager obj;
  obj.Add_new_Process();
  obj.Add_new_Process();
  obj.Add_new_Process();
  obj.Add_new_Process();
  obj.print();

  obj.remove_process_by_process_id(103);
  obj.print();

  obj.fork(100);
  obj.fork(100);
  obj.fork(100);
  obj.print();

  obj.Kill_parent_process(100);
  obj.print();
  
  obj.fork(101);
  obj.fork(101);
  obj.print();

  obj.Kill_child_processes(101);
  obj.print();

  
  obj.fork(101);
  obj.fork(101);
  obj.print();    


  int parent_id = obj.GetParentId(109);
    if(parent_id == 0)
    {   // This process can be a parent itself (assuming 0 indicates no parent)
        cout<<"This process can be a parent "<<parent_id<<endl;
    }
    else if(parent_id != -1)
    {
          cout<<"The parent id of this Process is "<<parent_id<<endl;   
    }

      int size;
      int *child_id = obj.GetChildIds(101,size);
      if(child_id != NULL)
      {  cout<<"The child Process for this parent id are "<<endl;
        for(int i = 0; i < size; i++)
        {
            cout<<*child_id<<endl;
            child_id++;
        }
      }
    
  obj.Kill_all_process();
  obj.print();
  

    return 0;
}