#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void pigRoll() {
    // Seed random number generator
    srand(static_cast<unsigned>(time(0)));

    int turnTotal = 0; // Total points for this turn
    bool rolling = true;

    cout << "Computer's turn begins.\n";

    while (rolling) {
        // Simulate rolling a die (1-6)
        int roll = (rand() % 6) + 1;
        cout << "Rolled: " << roll << "\n";

        if (roll == 1) {
            // Roll of 1 ends turn with no points
            cout << "Rolled a 1. Turn ends with 0 points.\n";
            turnTotal = 0;
            break;
        } else {
            // Add roll to turn total
            turnTotal += roll;
            cout << "Turn total: " << turnTotal << "\n";

            // Check if turn total meets or exceeds 20
            if (turnTotal >= 20) {
                cout << "Turn total reached 20 or more. Turn ends with " << turnTotal << " points.\n";
                rolling = false;
            }
        }
    }
}

int main() {
    char playAgain;
    do {
        pigRoll();
        cout << "\nPlay another turn? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Game over.\n";
    return 0;
}
