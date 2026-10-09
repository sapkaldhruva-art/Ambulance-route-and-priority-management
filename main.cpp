#include <iostream>
using namespace std;

struct Node {
    int id, priority;
    Node* next;
};

Node* head = nullptr;

void addAmbulance(int id, int priority) {
    Node* n = new Node{id, priority, nullptr};

    if (head == nullptr || priority < head->priority) {
        n->next = head;
        head = n;
        return;
    }

    Node* current = head;
    while (current->next != nullptr &&
           current->next->priority <= priority) {
        current = current->next;
    }

    n->next = current->next;
    current->next = n;
}

void displayAmbulances() {
    cout << "Ambulance Priority List\\n";
    for (Node* current = head; current != nullptr;
         current = current->next) {
        cout << "Ambulance " << current->id
             << " | Priority " << current->priority << '\\n';
    }
}

int main() {
    addAmbulance(101, 3);
    addAmbulance(102, 1);
    addAmbulance(103, 2);

    displayAmbulances();
    return 0;
}
