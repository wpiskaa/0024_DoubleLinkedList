#include <iostream>
#include <string>
using namespace std;

class node {
public:
    int nomMhs;
    node *next;
    node *prev;
};

class DoubleLinkedList {
private:
    node *START;

public:
    DoubleLinkedList() {
        START = NULL;
    }

    void addNode() {
        int nim;
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        node *newNode = new node();
        newNode->nomMhs = nim;

        // Insert di awal
        if (START == NULL || nim <= START->nomMhs) {
            if (START != NULL && nim == START->nomMhs) {
                cout << "\nDuplicate number not allowed" << endl;
                delete newNode;
                return;
            }
            newNode->next = START;
            if (START != NULL)
                START->prev = newNode;
            newNode->prev = NULL;
            START = newNode;
            return;
        }

        // Insert di tengah atau akhir
        node *current = START;
        while (current->next != NULL && current->next->nomMhs < nim) {
            current = current->next;
        }

        if (current->next != NULL && nim == current->next->nomMhs) {
            cout << "\nDuplicate roll number not allowed" << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL)
            current->next->prev = newNode;

        current->next = newNode;
    }

    void hapus() {
        if (START == NULL) {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number of the student to delete: ";
        cin >> rollNo;

        node *current = START;
        while (current != NULL && current->nomMhs != rollNo) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Record not found" << endl;
            return;
        }

        if (current == START) {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        } else {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        delete current;
        cout << "Record with roll number " << rollNo << " deleted" << endl;
    }

    void traverse() {
        if (START == NULL) {
            cout << "\nList is empty" << endl;
            return;
        }

        node *currentNode = START;
        cout << "\nRecords in ascending order of roll number:\n";
        int i = 1;
        while (currentNode != NULL) {
            cout << i << ". " << currentNode->nomMhs << endl;
            currentNode = currentNode->next;
            i++;
        }
    }

    void revtraverse() {
        if (START == NULL) {
            cout << "\nList is empty" << endl;
            return;
        }

        // Hitung jumlah node
        int count = 0;
        node *temp = START;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Pindah ke node terakhir
        node *currentNode = START;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }

        cout << "\nRecords in descending order of roll number:\n";
        while (currentNode != NULL) {
            cout << count << ". " << currentNode->nomMhs << endl;
            currentNode = currentNode->prev;
            count--;
        }
    }

    void searchData() {
        if (START == NULL) {
            cout << "\nList is empty" << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number to search: ";
        cin >> rollNo;

        node *current = START;
        while (current != NULL && current->nomMhs != rollNo) {
            current = current->next;
        }

        if (current == NULL) {
            cout << "Record not found\n";
        } else {
            cout << "Record found\n";
            cout << "Roll number: " << current->nomMhs << endl;
        }
    }
};

int main() {
    DoubleLinkedList list;
    char choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                list.addNode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.revtraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid option\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

    } while (choice != '6');

    return 0;
}
