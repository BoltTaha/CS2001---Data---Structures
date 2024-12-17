#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularSinglyLinkedList
{
private:
    Node *head;

public:
    CircularSinglyLinkedList()
    {
        head = NULL;
    }

    void insert(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->data;
            if (temp->next != head)
            {
                cout << " -> ";
            }
            temp = temp->next;
        } while (temp != head);
        cout << " (-> " << head->data << ")" << endl;
    }

   
    void deleteOddPosititonNodes()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        int count = 1;

        // delete head node
        if (count % 2 != 0)
        {
            Node *toDelete = head;
            head = head->next;

            Node *last = head;
            while (last->next != toDelete) // jab tak last ka next toDelete (purana head tha) nahi hota tab tak last ko update karte raho
            {
                last = last->next;
            }
            last->next = head;// last ka next ko newhead ko point kar do

            temp = head;// temp ko new head pe point kar do cuz old head is deleted now and new head is the next node of old head which is stored in last
            delete toDelete;
            count++;
        }

        while (temp->next != head)// jab tak temp ka next head nahi hota tab tak chalao
        {
            if (count % 2 != 0)
            {
                if (prev == NULL)// meaning temp is head node so update head to next node of head 
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            else
            {
                //prev is currently pointing to the node before temp
                prev = temp;// update prev to temp takay next node ka next pointer update kar sako
                temp = temp->next;
            }
            count++;
        }

        // check the last node
        if (count % 2 != 0)
        {
            if (prev == NULL)// this condition will only be true if there is only one node in the list
            {
                head = temp->next;
            }
            else// if there are more than one nodes in the list
            {
                //prev is currently pointing to the node before temp and temp is pointing to the last node
                prev->next = temp->next;
            }
            Node *toDelete = temp;
            delete toDelete;
        }
    }
};

int main()
{
    CircularSinglyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.display();
    list.deleteOddPosititonNodes();
    list.display();
    return 0;
}
