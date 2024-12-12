#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to search for a word in the dictionary file
void searchDictionary(const string& filename, const string& wordToFind) {
    ifstream file(filename);  // Open the dictionary file
    string word;
    bool found = false;

    // Check if the file opened successfully
    if (!file) {
        cout << "Error opening the file.\n";
        return;
    }

    // Read words from the file one by one using an EOF-controlled loop
    while (file >> word) {
        if (word == wordToFind) {
            found = true;
            break;  // Exit the loop if the word is found
        }
    }

    // Inform the user whether the word was found
    if (found) {
        cout << "The word \"" << wordToFind << "\" was found in the dictionary.\n";
    }
    else {
        cout << "The word \"" << wordToFind << "\" was not found in the dictionary.\n";
    }

    file.close();  // Close the file
}

int main() {
    string wordToFind;
    cout << "Enter a word to search for in the dictionary: ";
    cin >> wordToFind;

    // Call the search function with the dictionary file and the word to find
    searchDictionary("dictionary.txt", wordToFind);  // "dictionary.txt" is the file name

    return 0;
}
