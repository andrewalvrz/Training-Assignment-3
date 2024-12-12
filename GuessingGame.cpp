#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

void guessingGame() {
    srand(static_cast<unsigned>(time(0)));  // Seed the random number generator
    int randomNumber = rand() % 100 + 1;    // Generate random number between 1 and 100

    int guess = 0;
    bool correctGuess = false;

    cout << "Welcome to the Guessing Game! You have 5 attempts to guess the number (1-100).\n";

    // Allow up to 5 attempts
    for (int attempts = 1; attempts <= 5; ++attempts) {
        cout << "Attempt " << attempts << ": Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            --attempts; // Don't count invalid input as an attempt
            continue;
        }

        if (guess == randomNumber) {
            cout << "Congratulations! You guessed the correct number: " << randomNumber << endl;
            correctGuess = true;
            break; // Exit the loop if the guess is correct
        }
        else if (guess < randomNumber) {
            cout << "Too low! Try again.\n";
        }
        else {
            cout << "Too high! Try again.\n";
        }
    }

    if (!correctGuess) {
        cout << "Sorry, you've used all 5 attempts. The correct number was: " << randomNumber << endl;
    }
}

int main() {
    // Call the guessingGame function
    guessingGame();
    return 0;
}
