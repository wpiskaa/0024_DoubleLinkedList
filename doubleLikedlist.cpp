#include <iostream>
#include <string>
using namespace std;

class node
{
    public:
    int nomMhs;
    node *next;
    node *prev;
};

class DoubleLinkedList
{
    private:
    node *START;

    public:
    DoubleLinkedList()
    {
        START = NULL;

    }
    void addNode()
    {
        int nim;
        string nm;
        cout << "\nEnter the roll number of the student";
        cin >> nim;

        // Step 1: Allcate memory for new node
        node *newNode = new node();


        // Step 2: Assign value to the data fields
        newNode->nomMhs = nim;

        // Step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->nomMhs)
        {
            if (START != NULL && nim == START->nomMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
            }
            // Step 4: newNode.next = START
            newNode->next = START;

            //Step 5: start.prev = newNode (if start exists)
            if (START != NULL)
            START->prev = newNode;

            //Step 6: newNode.prev = NULL
             newNode->prev =  NULL;

             //Step 7: START = newNode
             START = newNode;
             
        }

        //Insert in between node
        //Step 8: Locate potition for insertion
        node *current = START;
        while (current->next !=NULL && current->next->nomMhs < nim)
    {
        current = current ->next;
    }

    if (current->next !=NULL && nim == current->next->nomMhs)
    {
        cout << "\nDuplicate roll number not allowed" << endl;
        return;
    }

    //Step 9: insert between current and current->next
    newNode->next = current->next; //Step 9a
    newNode->prev = current; // Step 9b

    //Insert last node
    if (current->next != NULL)
        current->next->prev = newNode; //Step 9c 

        current ->next = newNode; //Step 9d
    }

    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted";
        int rollNo;
        cin >> rollNo;

        node *current = START;


        //step 1: treverse the list to find the node
        while (current != NULL && current->nomMhs != rollNo)
        current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        //Step 2: if node is at the beginning
        if (current ==START)
        {
            START = current->next; //Step 2a: START = START.next
            if (START != NULL)
            START->prev = NULL; //Step 2b : START.prev = NULL
        }
        else{
            //Step 3: LInk previous node to the next of current
            current->prev->next = current->next;

            //Step 4: if current is not the last node
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        //Step 5: Delate the node
        delete current;
        cout << "Record with roll number " << rollNo << "Deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "\nList is empty" << endl;
            return;
        }

        //step 1: Mark first node as currentNode
        node *currentNode = START;

        //step2: Repeat until currentNode == NULL
        cout << "\nRecord in ascending order of roll number are:\n";
        int i = 0;
        while (currentNode != NULL)
        {

            cout << i + 1 << ". " << currentNode->nomMhs << " " << endl;

            //step3 : move to next node
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse()
    {
        
    }

};