#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> database;

void createItem() {
    string item;
    cout << "Enter item name: ";
    cin >> item;
    database.push_back(item);
    cout << "Item added successfully.\n";
}

void readItems() {
    cout << "Items in database:\n";
    for (size_t i = 0; i < database.size(); i++) {
        cout << i + 1 << ". " << database[i] << endl;
    }
}

void deleteItem() {
    int index;
    readItems();
    cout << "Enter item number to delete: ";
    cin >> index;

    if (index > 0 && index <= database.size()) {
        database.erase(database.begin() + index - 1);
        cout << "Item deleted.\n";
    } else {
        cout << "Invalid selection.\n";
    }
}

void showMenu() {
    cout << "\n--- CLI Menu ---\n";
    cout << "1. Add Item\n";
    cout << "2. List Items\n";
    cout << "3. Delete Item\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                createItem();
                break;
            case 2:
                readItems();
                break;
            case 3:
                deleteItem();
                break;
            case 4:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
