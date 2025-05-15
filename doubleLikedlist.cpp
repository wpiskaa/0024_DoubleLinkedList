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
    }


};