#include <iostream>
using namespace std;

int main() {
int choice;

cout << "Hydroelectric Stage Construction Planner" << endl;

cout << "\n1. Site Selection";
cout << "\n2. Planning and Design";
cout << "\n3. Dam Construction";
cout << "\n4. Water Channel Construction";
cout << "\n5. Turbine Installation";
cout << "\n6. Generator Installation";
cout << "\n7. Testing";
cout << "\n8. Display All Stages";
cout << "\nEnter your choice: ";
cin >> choice;

switch (choice) {
    case 1:
        cout << "Site Selection: Select a suitable location.";
        break;

    case 2:
        cout << "Planning and Design: Prepare the construction plan.";
        break;

    case 3:
        cout << "Dam Construction: Build a dam to store water.";
        break;

    case 4:
        cout << "Water Channel Construction: Build a channel to carry water.";
        break;

    case 5:
        cout << "Turbine Installation: Install the turbine.";
        break;

    case 6:
        cout << "Generator Installation: Install the generator to produce electricity.";
        break;

    case 7:
        cout << "Testing: Test the system to check its operation.";
        break;

    case 8:
        cout << "\n1. Site Selection";
        cout << "\n2. Planning and Design";
        cout << "\n3. Dam Construction";
        cout << "\n4. Water Channel Construction";
        cout << "\n5. Turbine Installation";
        cout << "\n6. Generator Installation";
        cout << "\n7. Testing";
        break;

    default:
        cout << "Invalid choice!";
}

return 0;

}
