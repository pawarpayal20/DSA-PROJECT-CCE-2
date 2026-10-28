#include <iostream>
#include <string>
#include <limits>
using namespace std;
#define MAX 50

class Warehouse {
    string location[MAX];
    int graph[MAX][MAX], visited[MAX], total;
public:
    Warehouse() {
        total = 0;
        for (int i = 0; i < MAX; i++)
            for (int j = 0; j < MAX; j++) graph[i][j] = 0;
    }
    void addLocation() {
        if (total == MAX) { cout << "Location limit reached!\n"; return; }
        cout << "Enter location name: ";
        getline(cin >> ws, location[total]);
        if (location[total].empty()) { cout << "Name cannot be empty!\n"; return; }
        cout << "Location added with ID: " << total++ << endl;
    }
    void displayLocations() {
        if (!total) { cout << "No locations available!\n"; return; }
        cout << "\nWarehouse Locations:\n";
        for (int i = 0; i < total; i++) cout << i << " : " << location[i] << endl;
    }
    void connectAisle() {
        if (total < 2) { cout << "Add at least two locations!\n"; return; }
        int a, b;
        displayLocations();
        cout << "Enter first location ID: "; cin >> a;
        cout << "Enter second location ID: "; cin >> b;
        if (a < 0 || a >= total || b < 0 || b >= total || a == b) {
            cout << "Invalid IDs or same location!\n"; return;
        }
        if (graph[a][b]) { cout << "Aisle already exists!\n"; return; }
        graph[a][b] = graph[b][a] = 1;
        cout << "Aisle connected successfully!\n";
    }
    void displayMatrix() {
        if (!total) { cout << "No locations available!\n"; return; }
        cout << "\nAdjacency Matrix:\n    ";
        for (int i = 0; i < total; i++) cout << i << " ";
        cout << endl;
        for (int i = 0; i < total; i++) {
            cout << i << " : ";
            for (int j = 0; j < total; j++) cout << graph[i][j] << " ";
            cout << endl;
        }
    }
    void displayConnections() {
        if (!total) { cout << "No locations available!\n"; return; }
        int id, found = 0;
        displayLocations();
        cout << "Enter location ID: "; cin >> id;
        if (id < 0 || id >= total) { cout << "Invalid ID!\n"; return; }
        cout << "Connections of " << location[id] << ":\n";
        for (int i = 0; i < total; i++)
            if (graph[id][i]) { cout << location[i] << endl; found = 1; }
        if (!found) cout << "No connected locations!\n";
    }
    void DFS(int v) {
        visited[v] = 1;
        cout << location[v] << " -> ";
        for (int i = 0; i < total; i++)
            if (graph[v][i] && !visited[i]) DFS(i);
    }
    void exploreDFS() {
        if (!total) { cout << "No locations available!\n"; return; }
        int start, count = 0;
        displayLocations();
        cout << "Enter starting location ID: "; cin >> start;
        if (start < 0 || start >= total) { cout << "Invalid ID!\n"; return; }
        for (int i = 0; i < total; i++) visited[i] = 0;
        cout << "\nDFS Traversal:\n";
        DFS(start);
        cout << "END\n";
        for (int i = 0; i < total; i++) if (visited[i]) count++;
        cout << "Reachable locations (including start): " << count << endl;
        cout << "Unreachable locations: " << total - count << endl;
    }
};

int main() {
    Warehouse w;
    int choice;
    do {
        cout << "\n===== WAREHOUSE MANAGEMENT =====\n";
        cout << "1. Add Location\n2. Connect Aisles\n3. Display Locations\n";
        cout << "4. Display Adjacency Matrix\n5. Display Connections\n";
        cout << "6. Explore Using DFS\n7. Exit\nEnter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number.\n";
            continue;
        }
        switch (choice) {
            case 1: w.addLocation(); break;
            case 2: w.connectAisle(); break;
            case 3: w.displayLocations(); break;
            case 4: w.displayMatrix(); break;
            case 5: w.displayConnections(); break;
            case 6: w.exploreDFS(); break;
            case 7: cout << "Program terminated.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}
