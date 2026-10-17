#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Clothing {
public:
    string item, color, fabric, category;
    Clothing* next;

    Clothing(string i, string c, string f, string cat) {
        item = i;
        color = c;
        fabric = f;
        category = cat;
        next = NULL;
    }
};

class Wardrobe {
private:
    Clothing* head;

public:
    Wardrobe() {
        head = NULL;
    }

    void addClothing() {
        string item, color, fabric, category;

        cout << "\nEnter clothing item: ";
        getline(cin, item);

        cout << "Enter color: ";
        getline(cin, color);

        cout << "Enter fabric type: ";
        getline(cin, fabric);

        cout << "Enter category (Top/Bottom/Other): ";
        getline(cin, category);

        if (item.empty() || color.empty() ||
            fabric.empty() || category.empty()) {
            cout << "Please enter all details.\n";
            return;
        }

        Clothing* newNode =
            new Clothing(item, color, fabric, category);

        if (head == NULL) {
            head = newNode;
        } else {
            Clothing* temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "\nClothing item added successfully!\n";
    }

    void viewWardrobe() {
        cout << "\n===== WARDROBE ITEMS =====\n";

        if (head == NULL) {
            cout << "Wardrobe is empty.\n";
            return;
        }

        Clothing* temp = head;
        int i = 1;

        while (temp != NULL) {
            cout << "\nItem " << i++ << endl;
            cout << "Name: " << temp->item << endl;
            cout << "Color: " << temp->color << endl;
            cout << "Fabric: " << temp->fabric << endl;
            cout << "Category: " << temp->category << endl;

            temp = temp->next;
        }
    }

    void findMatchingClothes() {
        cout << "\n===== MATCHING CLOTHES =====\n";

        bool found = false;

        Clothing* a = head;

        while (a != NULL) {
            Clothing* b = a->next;

            while (b != NULL) {
                if (a->category != b->category) {
                    cout << a->item << " ("
                         << a->color << ") + "
                         << b->item << " ("
                         << b->color << ")\n";

                    found = true;
                }

                b = b->next;
            }

            a = a->next;
        }

        if (!found) {
            cout << "No matching combinations found.\n";
        }
    }

    void outfitSuggestions() {
        cout << "\n===== OUTFIT SUGGESTIONS =====\n";

        bool found = false;

        Clothing* a = head;

        while (a != NULL) {
            Clothing* b = head;

            while (b != NULL) {
                if (a->category == "Top" &&
                    b->category == "Bottom") {
                    cout << a->item << " ("
                         << a->color << ") + "
                         << b->item << " ("
                         << b->color << ")\n";

                    found = true;
                }

                b = b->next;
            }

            a = a->next;
        }

        if (!found) {
            cout << "Add at least one Top and one Bottom.\n";
        }
    }

    ~Wardrobe() {
        while (head != NULL) {
            Clothing* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Wardrobe w;
    int choice = 0;

    do {
        cout << "\n===== MODULAR WARDROBE & FABRIC PAIRING ENGINE =====\n";
        cout << "1. Add Clothing Item\n";
        cout << "2. View Wardrobe Items\n";
        cout << "3. Find Matching Clothes\n";
        cout << "4. Get Outfit Suggestions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                w.addClothing();
                break;

            case 2:
                w.viewWardrobe();
                break;

            case 3:
                w.findMatchingClothes();
                break;

            case 4:
                w.outfitSuggestions();
                break;

            case 5:
                cout << "Thank you for using Wardrobe Engine!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
