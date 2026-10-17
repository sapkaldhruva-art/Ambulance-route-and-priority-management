#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    string phone;
    Node* left;
    Node* right;

    Node(string n, string p) {
        name = n;
        phone = p;
        left = NULL;
        right = NULL;
    }
};

class PhoneBook {
private:
    Node* root;

    // Insert or update a contact
    Node* insertNode(Node* node, string name, string phone) {
        if (node == NULL) {
            return new Node(name, phone);
        }

        if (name < node->name) {
            node->left = insertNode(node->left, name, phone);
        }
        else if (name > node->name) {
            node->right = insertNode(node->right, name, phone);
        }
        else {
            node->phone = phone;
        }

        return node;
    }

    // Search for a contact
    Node* searchNode(Node* node, string name) {
        if (node == NULL || node->name == name) {
            return node;
        }

        if (name < node->name) {
            return searchNode(node->left, name);
        }

        return searchNode(node->right, name);
    }

    // Display contacts alphabetically
    void displayInOrder(Node* node) {
        if (node == NULL) {
            return;
        }

        displayInOrder(node->left);

        cout << "Name: " << node->name
             << " | Phone: " << node->phone << endl;

        displayInOrder(node->right);
    }

    // Find first name alphabetically
    Node* findFirst(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        while (node->left != NULL) {
            node = node->left;
        }

        return node;
    }

    // Find last name alphabetically
    Node* findLast(Node* node) {
        if (node == NULL) {
            return NULL;
        }

        while (node->right != NULL) {
            node = node->right;
        }

        return node;
    }

    // Free memory
    void deleteTree(Node* node) {
        if (node == NULL) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    PhoneBook() {
        root = NULL;
    }

    ~PhoneBook() {
        deleteTree(root);
    }

    // Add a contact
    void addContact() {
        string name, phone;

        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter phone number: ";
        getline(cin, phone);

        if (name.empty() || phone.empty()) {
            cout << "Name and phone number cannot be empty.\n";
            return;
        }

        Node* existing = searchNode(root, name);

        root = insertNode(root, name, phone);

        if (existing != NULL) {
            cout << "Contact updated successfully!\n";
        }
        else {
            cout << "Contact added successfully!\n";
        }
    }

    // Search a contact
    void searchContact() {
        string name;

        cout << "Enter name to search: ";
        getline(cin, name);

        Node* result = searchNode(root, name);

        if (result != NULL) {
            cout << "\nContact found!\n";
            cout << "Name: " << result->name
                 << " | Phone: " << result->phone << endl;
        }
        else {
            cout << "Contact not found!\n";
        }
    }

    // Display all contacts
    void displayContacts() {
        if (root == NULL) {
            cout << "Phone book is empty.\n";
            return;
        }

        cout << "\n--- Contacts in Alphabetical Order ---\n";
        displayInOrder(root);
    }

    // Display first contact
    void showFirstName() {
        Node* first = findFirst(root);

        if (first == NULL) {
            cout << "Phone book is empty.\n";
        }
        else {
            cout << "First name alphabetically: "
                 << first->name << " | Phone: "
                 << first->phone << endl;
        }
    }

    // Display last contact
    void showLastName() {
        Node* last = findLast(root);

        if (last == NULL) {
            cout << "Phone book is empty.\n";
        }
        else {
            cout << "Last name alphabetically: "
                 << last->name << " | Phone: "
                 << last->phone << endl;
        }
    }
};

int main() {
    PhoneBook pb;
    int choice;

    do {
        cout << "\n========== PHONE BOOK USING BST ==========\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Display Contacts (Alphabetical)\n";
        cout << "4. Find First Name\n";
        cout << "5. Find Last Name\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        cin.ignore(10000, '\n');

        switch (choice) {
            case 1:
                pb.addContact();
                break;

            case 2:
                pb.searchContact();
                break;

            case 3:
                pb.displayContacts();
                break;

            case 4:
                pb.showFirstName();
                break;

            case 5:
                pb.showLastName();
                break;

            case 0:
                cout << "Exiting Phone Book. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
