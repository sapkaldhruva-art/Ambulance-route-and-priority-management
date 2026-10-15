#include <iostream>
using namespace std;

struct Node {
    int id, priority;
    Node* next;
};

Node* head = NULL;

// Add ambulance according to priority
void addAmbulance(int id, int priority) {
    Node* n = new Node{id, priority, NULL};

    if (head == NULL || priority < head->priority) {
        n->next = head;
        head = n;
    } else {
        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->priority <= priority) {
            temp = temp->next;
        }

        n->next = temp->next;
        temp->next = n;
    }

    cout << "Ambulance added successfully!\n";
}

// Display ambulances
void display() {
    Node* temp = head;

    if (head == NULL) {
        cout << "No ambulances available.\n";
        return;
    }

    cout << "\nAmbulance Priority List:\n";

    while (temp != NULL) {
        cout << "ID: " << temp->id
             << " Priority: " << temp->priority << endl;
        temp = temp->next;
    }
}

// Dispatch highest-priority ambulance
void dispatch() {
    if (head == NULL) {
        cout << "No ambulance available.\n";
        return;
    }

    Node* temp = head;

    cout << "Ambulance " << temp->id
         << " dispatched!\n";

    head = head->next;
    delete temp;
}

// Count ambulances
void countAmbulances() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Total ambulances: " << count << endl;
}

int main() {
    int choice, id, priority;

    do {
        cout << "\n--- Ambulance Management System ---\n";
        cout << "1. Add Ambulance\n";
        cout << "2. Display Ambulances\n";
        cout << "3. Dispatch Ambulance\n";
        cout << "4. Count Ambulances\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Ambulance ID: ";
                cin >> id;

                cout << "Enter Priority (1-5): ";
                cin >> priority;

                if (id <= 0 || priority < 1 || priority > 5) {
                    cout << "Invalid ID or priority!\n";
                } else {
                    addAmbulance(id, priority);
                }
                break;

            case 2:
                display();
                break;

            case 3:
                dispatch();
                break;

            case 4:
                countAmbulances();
                break;

            case 5:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}