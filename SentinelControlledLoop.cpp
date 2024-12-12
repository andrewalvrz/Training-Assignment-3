#include <iostream>
using namespace std;

void calculateAverageGrades() {
    int grade;
    int totalGrades = 0;
    int count = 0;

    cout << "Enter a grade, or a negative number to stop:  " << endl;

    while (true) {
        cin >> grade;

        // Check for sentinel value
        if (grade < 0) {
            break;
        }

        // Validate input
        if (!cin) {
            cin.ignore(2000, '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a valid grade: " << endl;
            continue;
        }

        totalGrades += grade;
        count++;
    }

    if (count > 0) {
        double average = totalGrades / count;
        cout << "The average is: " << average << endl;
    }
    else {
        cout << "No grades were entered." << endl;
    }
}

int main() {
    calculateAverageGrades();
    return 0;
}
