#include <iostream>
#include <vector>
#include <string>
using namespace std;

class WarehouseGraph {
private:
    vector<string> locations;
    vector< vector<int> > adj;

    int findLocation(const string& name) const {
        for (int i = 0; i < (int)locations.size(); i++)
            if (locations[i] == name) return i;
        return -1;
    }

public:
    void addLocation(const string& name) {
        if (findLocation(name) == -1) {
            locations.push_back(name);
            adj.push_back(vector<int>());
        }
    }

    bool hasLocation(const string& name) const {
        return findLocation(name) != -1;
    }

    void addAisle(const string& a, const string& b) {
        addLocation(a);
        addLocation(b);
        int u = findLocation(a), v = findLocation(b);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void displayGraph() const {
        cout << "\nWarehouse Graph (Location: Connected locations)\n";
        for (int i = 0; i < (int)locations.size(); i++) {
            cout << locations[i] << ": ";
            for (int j = 0; j < (int)adj[i].size(); j++) {
                cout << locations[adj[i][j]];
                if (j + 1 < (int)adj[i].size()) cout << " -> ";
            }
            cout << endl;
        }
    }

    void DFS(const string& startName) const {
        int start = findLocation(startName);
        if (start == -1) {
            cout << "Error: Location " << startName << " does not exist.\n";
            return;
        }

        vector<int> visited(locations.size(), 0), stack;
        stack.push_back(start);
        int count = 0;
        cout << "\nDFS traversal from " << startName << ": ";

        while (!stack.empty()) {
            int u = stack.back();
            stack.pop_back();
            if (visited[u]) continue;
            visited[u] = 1;
            count++;
            cout << locations[u] << " ";

            for (int j = (int)adj[u].size() - 1; j >= 0; j--)
                if (!visited[adj[u][j]]) stack.push_back(adj[u][j]);
        }
        cout << "\nReachable locations: " << count << endl;
    }
};

int main() {
    WarehouseGraph warehouse;
    int n, m;
    cout << "=== Warehouse Location Explorer using DFS ===\n";
    cout << "Enter number of warehouse locations: ";
    if (!(cin >> n) || n <= 0) { cout << "Invalid number.\n"; return 1; }

    cout << "Enter location names (one word each):\n";
    for (int i = 0; i < n; i++) {
        string name;
        cout << "Location " << i + 1 << ": ";
        cin >> name;
        if (warehouse.hasLocation(name)) {
            cout << "Duplicate location name.\n";
            return 1;
        }
        warehouse.addLocation(name);
    }

    cout << "Enter number of connecting aisles: ";
    if (!(cin >> m) || m < 0) { cout << "Invalid number of aisles.\n"; return 1; }

    cout << "Enter each aisle as two location names:\n";
    for (int i = 0; i < m; i++) {
        string a, b;
        cout << "Aisle " << i + 1 << ": ";
        cin >> a >> b;
        if (!warehouse.hasLocation(a) || !warehouse.hasLocation(b)) {
            cout << "Both locations must be declared first.\n";
            return 1;
        }
        warehouse.addAisle(a, b);
    }

    warehouse.displayGraph();
    string start;
    cout << "\nEnter starting location for DFS: ";
    cin >> start;
    warehouse.DFS(start);
    return 0;
}
