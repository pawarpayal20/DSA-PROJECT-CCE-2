#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id, days;
    string name;
    Node* next;
};

Node* head = NULL;

void addStage() {
    Node* n = new Node;

    cout << "Enter Stage ID: ";
    cin >> n->id;

    cout << "Enter Stage Name: ";
    cin >> ws;
    getline(cin, n->name);

    cout << "Enter Days Required: ";
    cin >> n->days;

    n->next = NULL;

    if (head == NULL) {
        head = n;
    } else {
        Node* t = head;

        while (t->next != NULL)
            t = t->next;

        t->next = n;
    }

    cout << "Stage added successfully!\n";
}

void displayStages() {
    if (head == NULL) {
        cout << "No construction stages available!\n";
        return;
    }

    Node* t = head;
    int total = 0;

    cout << "\n--- Construction Plan ---\n";

    while (t != NULL) {
        cout << "Stage ID: " << t->id << endl;
        cout << "Stage Name: " << t->name << endl;
        cout << "Days Required: " << t->days << endl;
        cout << "------------------------\n";

        total += t->days;
        t = t->next;
    }

    cout << "Total Construction Days: " << total << endl;
}

void searchStage() {
    int id;

    cout << "Enter Stage ID to search: ";
    cin >> id;

    Node* t = head;

    while (t != NULL) {
        if (t->id == id) {
            cout << "Stage Found!\n";
            cout << "Stage Name: " << t->name << endl;
            cout << "Days Required: " << t->days << endl;
            return;
        }

        t = t->next;
    }

    cout << "Stage not found!\n";
}

void deleteStage() {
    int id;

    cout << "Enter Stage ID to delete: ";
    cin >> id;

    Node* t = head;
    Node* prev = NULL;

    while (t != NULL && t->id != id) {
        prev = t;
        t = t->next;
    }

    if (t == NULL) {
        cout << "Stage not found!\n";
        return;
    }

    if (prev == NULL)
        head = t->next;
    else
        prev->next = t->next;

    delete t;

    cout << "Stage deleted successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== HYDROELECTRIC STAGE CONSTRUCTION PLANNER =====\n";
        cout << "1. Add Construction Stage\n";
        cout << "2. Display Construction Plan\n";
        cout << "3. Search Construction Stage\n";
        cout << "4. Delete Construction Stage\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addStage();
                break;

            case 2:
                displayStages();
                break;

            case 3:
                searchStage();
                break;

            case 4:
                deleteStage();
                break;

            case 5:
                cout << "Thank you for using the planner!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
