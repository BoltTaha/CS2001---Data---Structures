#include <iostream>

using namespace std;

class node
{
public:
    int value;
    node *next;
    node *prev;

    node(int value)
    {
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkList
{
    node *head;
    int length;

public:
    DoublyLinkList()
    {
        head = NULL;
        length = 0;
    }
    ~DoublyLinkList()
    {
        while (head != NULL)
        {
            remove(1);
        }
    }
    int getLength()
    {
        return length;
    }
    void insert(int val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        node *n = new node(val);

        if (pos == 1)
        {
            n->next = head;
            if (head != NULL)
                head->prev = n;
            head = n;
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            if (n->next != NULL)
                n->next->prev = n;
            curr->next = n;
            n->prev = curr;
        }
        length++;
    }
    void remove(int pos)
    {
        if (pos <= 0 || pos > length)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (length == 0)
        {
            cout << "Doubly LinkList is empty" << endl;
            return;
        }
        node *curr = head;
        if (pos == 1)
        {
            head = head->next;
            if (head != NULL)
                head->prev = curr->prev;
            delete curr;
        }
        else
        {
            node *slow = head;
            for (int i = 1; i < pos; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = curr->next;
            if (curr->next != NULL)
                curr->next->prev = slow;
            delete curr;
        }
        length--;
    }
    void clear()
    {
        if (length == 0)
        {
            cout << "Doubly Link List is already empty" << endl;
            return;
        }
        while (head != NULL)
        {
            remove(1);
        }
    }
    void update(int val, int pos)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Invalid Position" << endl;
            return;
        }
        if (length == 0)
        {
            cout << "Doubly LinkList is empty" << endl;
            return;
        }

        node *curr = head;

        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        curr->value = val;
    }
    int get(int pos)
    {
        if (pos < 0 || pos > length)
        {
            cout << "Invalid Position" << endl;
            return -1;
        }
        node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        return curr->value;
    }
    bool find(int no)
    {
        node *curr = head;

        for (int i = 1; i <= length; i++)
        {
            if (curr->value == no)
                return true;
            curr = curr->next;
        }

        return false;
    }
    void print()
    {
        if (length == 0)
        {
            cout << "Doubly Link List is empty" << endl;
            return;
        }
        node *curr = head;
        cout << endl;

        while (curr != NULL)
        {
            cout << curr->value << "\t";
            curr = curr->next;
        }
        cout << endl;
    }
    void copy(DoublyLinkList &l2)
    {
        if (l2.length == 0)
        {
            cout << "List is empty" << endl;
            return;
        }
        while (head!=NULL)
        {
            remove(1);
        }
        node *curr = l2.head;

        for (int i = 1; i <= l2.length; i++)
        {
            insert(curr->value, i);
            curr = curr->next;
        }
        length = l2.length;
    }
    
};

int main()
{
    DoublyLinkList l,l2;
    
    l.insert(1,1);
    //invalid case for checking
    // l.insert(2,3);
    l.insert(2,2);
    l.insert(3,3);
    l.insert(4,4);
    l.insert(5,5);
    l.print();

    l2.insert(100,1);
    l2.insert(200,2);
    l2.insert(300,3);
    
    cout<<"\nLength of L1= "<<l.getLength()<<endl;
    cout<<"Length of L2= "<<l2.getLength()<<endl;


    l.remove(1);
    l.print();
    //checking
    l.remove(-1);
    l.remove(5);
    l.print();

    l.clear();
    l.print();

    cout<<endl<<l.get(1)<<endl;
    cout<<endl<<l.get(4)<<endl;
    cout<<endl<<l.get(3)<<endl;

    l.update(10,1);
    l.update(50,4);
    l.update(30,3);
    l.print();

    cout<<l.find(50)<<endl;
    cout<<l.find(3)<<endl;
    cout<<l.find(80)<<endl;

    l2.print();
    l.copy(l2);
    l.print();
    l2.print();

    return 0;
}
