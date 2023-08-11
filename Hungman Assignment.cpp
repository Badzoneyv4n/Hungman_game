//GROUP WORK {Hungman game}

//programmers						reg numbers
//NDIZEYE BEZA YVAN					222002355
//RUGABA HIRWA NIXON				222012137


#include <iostream>
#include <string>

using namespace std;

const int MAX_GUESSES = 6;
const int MAX_WARNINGS = 3;
const string VOWELS = "aeiou";

int main() {
  // Generate a random word
  string word = "morning";

  // Initialize the game state
  int guesses_remaining = MAX_GUESSES;
  int warnings_remaining = MAX_WARNINGS;
  string guessed_letters = "";

  // Play the game
  while (guesses_remaining > 0) {
    // Display the game state
    cout << "Guesses remaining: " << guesses_remaining << endl;
    cout << "Warnings remaining: " << warnings_remaining << endl;
    cout << "Guessed letters: " << guessed_letters << endl;

    // Get the user's guess
    char guess;
    cout << "Enter a guess: ";
    cin >> guess;

    // Check for valid guess
    if (!isalpha(guess)) {
      if (warnings_remaining > 0) {
        warnings_remaining--;
        cout << "Invalid guess. You have " << warnings_remaining << " warnings remaining." << endl;
      } else {
        guesses_remaining--;
        cout << "Invalid guess. You lose a guess." << endl;
      }
    } else {
      // Check if the guess is in the word
      bool found = false;
      for (int i = 0; i < word.length(); i++) {
        if (guess == word[i]) {
          found = true;
          guessed_letters += guess;
          break;
        }
      }

      // Update the game state
      if (found) {
        cout << "Correct!" << endl;
      } else {
        if (guess == 'a' || guess == 'e' || guess == 'i' || guess == 'o' || guess == 'u') {
          guesses_remaining -= 2;
        } else {
          guesses_remaining--;
        }
        cout << "Incorrect. ";
        if (guesses_remaining == 0) {
          cout << "You lose!" << endl;
        } else {
          cout << "You have " << guesses_remaining << " guesses remaining." << endl;
        }
      }
    }
  }

  // Check if the player won
  if (guessed_letters == word) {
    cout << "You win! Your score is " << guesses_remaining * word.length() << "." << endl;
  } else {
    cout << "You lose! The word was " << word << "." << endl;
  }

  return 0;
}

