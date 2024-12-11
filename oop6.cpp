#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Item {
public:
    string name;
    int quantity, cost, code;

    // Operators for comparison
    bool operator == (const Item& i) const { 
        return code == i.code; 
    }

    // Operators for comparison
    bool operator < (const Item& i) const { 
        return cost < i.cost; 
    }
};

vector<Item> items;

// Function to insert an item
void insert() {
    Item i;
    cout << "\nEnter Item Name: ";
    cin >> i.name;
    cout << "Enter Item Quantity: ";
    cin >> i.quantity;
    cout << "Enter Item Cost: ";
    cin >> i.cost;
    cout << "Enter Item Code: ";
    cin >> i.code;
    items.push_back(i);
    cout << "\nItem added successfully!\n";
}

// Function to display all items
void display() {
    if (items.empty()) {
        cout << "\nNo items to display.\n";
        return;
    }
    for (auto i : items) {
        cout << "\nItem Name: " << i.name
             << "\nItem Quantity: " << i.quantity
             << "\nItem Cost: " << i.cost
             << "\nItem Code: " << i.code << "\n";
    }
}

// Function to search for an item
void search() {
    int code;
    cout << "\nEnter Item Code to search: ";
    cin >> code;

    Item temp;
    temp.code = code;

    auto it = find(items.begin(), items.end(), temp);

    if (it != items.end()) {
        cout << "Found: " ;
    } else {
        cout << "Not Found\n";
    }    
}

// Function to delete an item
void removeItem() {
    int code;
    cout << "\nEnter Item Code to delete: ";
    cin >> code;

    bool found = false;
    for (auto it = items.begin(); it != items.end(); ++it) {
        if (it->code == code) {
            items.erase(it);
            cout << "\nItem deleted successfully!\n";
            found = true;
            break; // Stop searching after deleting the first match
        }
    }

    if (!found) {
        cout << "\nItem not found.\n";
    }
}

// Function to sort items by cost
void sortItems() {
    sort(items.begin(), items.end());
    cout << "\nItems sorted by cost.\n";
}

int main() {
    int choice;

    do {
        cout << "\nMenu:"
             << "\n1. Insert Item"
             << "\n2. Display Items"
             << "\n3. Search Item"
             << "\n4. Sort Items by Cost"
             << "\n5. Delete Item"
             << "\n6. Exit"
             << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                sortItems();
                break;
            case 5:
                removeItem();
                break;
            case 6:
                cout << "\nExiting program. Goodbye!\n";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while (true);
}
