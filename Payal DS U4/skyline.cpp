#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int height;
    Node *left, *right;

    Node(int h) {
        height = h;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, int h) {
    if (root == NULL)
        return new Node(h);

    if (h < root->height)
        root->left = insert(root->left, h);
    else
        root->right = insert(root->right, h);

    return root;
}

// Function to free BST memory to prevent memory leaks
void clearTree(Node* root) {
    if (root == NULL) return;
    clearTree(root->left);
    clearTree(root->right);
    delete root;
}

void addBuilding(vector<int>& b, Node*& root) {
    int h;
    cout << "Enter building height: ";
    cin >> h;

    if (h <= 0) {
        cout << "Enter a positive height!\n";
        return;
    }

    b.push_back(h);
    root = insert(root, h);

    cout << "Building added successfully!\n";
}

void displaySkyline(vector<int>& b) {
    if (b.empty()) {
        cout << "No buildings available!\n";
        return;
    }

    int maxH = b[0];
    for (size_t i = 1; i < b.size(); i++) {
        if (b[i] > maxH) {
            maxH = b[i];
        }
    }

    cout << "\n      SKYLINE VIEW\n\n";

    for (int row = maxH; row >= 1; row--) {
        for (size_t i = 0; i < b.size(); i++) {
            if (b[i] >= row)
                cout << " ## ";
            else
                cout << "    ";
        }
        cout << endl;
    }

    for (size_t i = 0; i < b.size(); i++) {
        cout << " B" << i + 1 << " ";
    }

    cout << "\n\n";
}

void displayHeights(vector<int>& b) {
    if (b.empty()) {
        cout << "No buildings available!\n";
        return;
    }

    cout << "\nBUILDING HEIGHTS\n";

    for (size_t i = 0; i < b.size(); i++) {
        cout << "Building " << i + 1 << ": " << b[i] << endl;
    }
}

void displaySides(vector<int>& b) {
    if (b.empty()) {
        cout << "No buildings available!\n";
        return;
    }

    int maxH = 0;

    cout << "\nLEFT SIDE VIEW: ";

    for (size_t i = 0; i < b.size(); i++) {
        if (b[i] > maxH) {
            cout << b[i] << " ";
            maxH = b[i];
        }
    }

    maxH = 0;
    cout << "\nRIGHT SIDE VIEW: ";

    for (int i = (int)b.size() - 1; i >= 0; i--) {
        if (b[i] > maxH) {
            cout << b[i] << " ";
            maxH = b[i];
        }
    }

    cout << endl;
}

int main() {
    vector<int> buildings;
    Node* root = NULL;
    int choice, n;

    do {
        cout << "\n===== SKYLINE VISUALISATION =====\n";
        cout << "1. Enter Buildings\n";
        cout << "2. Add More Buildings\n";
        cout << "3. Display Skyline\n";
        cout << "4. Display Building Heights\n";
        cout << "5. Display Left and Right Views\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "How many buildings? ";
                cin >> n;

                if (n <= 0) {
                    cout << "Enter a positive number!\n";
                    break;
                }

                for (int i = 0; i < n; i++) {
                    addBuilding(buildings, root);
                }
                break;

            case 2:
                addBuilding(buildings, root);
                break;

            case 3:
                displaySkyline(buildings);
                break;

            case 4:
                displayHeights(buildings);
                break;

            case 5:
                displaySides(buildings);
                break;

            case 6:
                cout << "Thank you for using Skyline Visualisation!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    clearTree(root);

    return 0;
}
