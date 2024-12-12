#include <iostream>
#include <limits> 
using namespace std;

void flagControlledLoop() {
    char iceCream;
    bool validInput = false;

    // Loop until the user provides a valid input ('y' or 'n')
    while (!validInput) {
        cout << "Do you like ice cream? (y/n): ";
        cin >> iceCream;

        if (iceCream == 'y' || iceCream == 'n') {
            validInput = true; // Exit loop if input is valid
        }
        else {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
        }
    }

    int age = 0;
    validInput = false; // Reset for next input validation

    // Loop until the user provides a valid numeric age
    while (!validInput) {
        cout << "Enter your age: ";
        cin >> age;

        if (cin.fail() || age < 0) {
            cout << "Invalid input. Age must be a number.\n";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining input
        }
        else {
            validInput = true; // Exit loop if input is valid
        }
    }

    cout << "You entered: " << (iceCream == 'y' ? "Yes" : "No")
        << " for liking ice cream, and age: " << age << endl;
}

int main() {
    // Call the flagControlledLoop function
    flagControlledLoop();
    return 0;
}
