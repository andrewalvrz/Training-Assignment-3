#include <iostream>
using namespace std;

void guessNumber() {
    int seed = 0;

    // Validate input
    do {
        cout << "Enter a seed value (1000-4000) or 0 to use the computer's time as the seed: " << endl;
        cin >> seed;

        if (cin.fail() || (seed != 0 && (seed < 1000 || seed > 4000))) {
            cout << "Invalid input. Please enter a whole number between 1000 and 4000, or 0." << endl;
            cin.clear();  // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input (clear up to 1000 characters or until a newline)
        }
    } while (cin.fail() || (seed != 0 && (seed < 1000 || seed > 4000)));

    // Set seed for random number generation
    if (seed == 0) {
        srand(time(0)); // Use the computer's current time
    } else {
        srand(seed); // Use the user-provided seed
    }

    // Game setup
    int randomNumber = rand() % 100 + 1; // Random number between 1 and 100
    int guess = 0;
    int attempts = 5;

    cout << "You have 5 attempts to guess a number between 1 and 100" << endl;

    for (int i = 0; i < attempts; ++i) {
        cout << "Attempt " << (i + 1) << ": Enter your guess: ";

        while (!(cin >> guess)) {  // Check if input is a number
            cout << "Invalid input. Please enter a whole number: ";
            cin.clear();  // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input (clear up to 1000 characters or until a newline)
        }

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the number!" << endl;
            break;
        } else if (guess < randomNumber) {
            cout << "Too low. Try again." << endl;
        } else {
            cout << "Too high. Try again." << endl;
        }

        if (i == attempts - 1) {
            cout << "You've used all your attempts. The correct number was " << randomNumber << "." << endl;
        }
    }
}

int main() {
    guessNumber();
    return 0;
}
