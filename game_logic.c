#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "leader_board.h"  // Include the leaderboard header
#include "game_logic.h"  // Assuming all necessary headers are included
#include "user_profiles.h"  // Include user profile management

// Function to print the hangman figure based on incorrect guesses
void printHangman(int incorrectGuesses) {
    printf("  +----+\n");
    printf("  |    |\n");

    if (incorrectGuesses >= 1)
        printf("  O    |\n");
    else
        printf("       |\n");

    if (incorrectGuesses >= 2)
        printf("  |    |\n");
    else
        printf("       |\n");

    if (incorrectGuesses >= 3)
        printf(" /|\\   |\n");
    else
        printf("       |\n");

    if (incorrectGuesses >= 4)
        printf(" / \\   |\n");
    else
        printf("       |\n");

    printf("       |\n");
    printf(" ========\n");
}

// Function to play the game
void playGame(User *user, int difficultyLevel) {
    // List of words and hints
    char words[3][20] = {"canteen", "library", "electronic"};
    char hints[3][50] = {"food mood", "please maintain silence", "devices run by circuits"};

    // Select word and hint based on difficulty level
    char *word;
    char *hint;

    if (difficultyLevel == 1) { // Easy
        word = words[0];
        hint = hints[0];
    } else if (difficultyLevel == 2) { // Medium
        word = words[1];
        hint = hints[1];
    } else { // Hard
        word = words[2];
        hint = hints[2];
    }

    int wordLength = strlen(word);
    char guessedWord[wordLength + 1]; // To store the guessed word (initially blank)
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    int incorrectGuesses = 0;
    int maxIncorrectGuesses = 6;
    char guessedLetter;
    int found;

    printf("Hint: %s\n", hint);
    printf("Word: %s\n", guessedWord);
    printf("\n");

    // Start the game loop
    while (incorrectGuesses < maxIncorrectGuesses) {
        printf("Enter a letter to guess: ");
        scanf(" %c", &guessedLetter);  // Added space to handle previous newline
        guessedLetter = tolower(guessedLetter);  // Convert to lowercase for case insensitivity

        found = 0;
        // Check the guessed letter against the word
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guessedLetter && guessedWord[i] == '_') {
                guessedWord[i] = guessedLetter;
                found = 1;
            }
        }

        // If the letter is not found, increment the incorrect guesses
        if (!found) {
            incorrectGuesses++;
        }

        // Print the hangman figure based on incorrect guesses
        printHangman(incorrectGuesses);

        // Print the guessed word so far
        printf("Word: %s\n", guessedWord);
        printf("Incorrect guesses left: %d\n", maxIncorrectGuesses - incorrectGuesses);

        // Check if the user has guessed all letters
        if (strcmp(word, guessedWord) == 0) {
            printf("Congratulations, %s! You guessed the word correctly.\n", user->username);
            user->score += 10; // Example score increment
            break;
        }
    }

    // Game over if maximum incorrect guesses are reached
    if (incorrectGuesses == maxIncorrectGuesses) {
        printf("Game Over! The word was: %s\n", word);
    }

    printf("Your score: %d\n", user->score);

    // Ask to show leaderboard or exit
    printf("Would you like to:\n1. Show Leaderboard\n2. Exit\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        displayLeaderboard(); // Assuming this function is already implemented
    } else {
        printf("Exiting the game...\n");
    }

    // Update leaderboard with the final score
    updateScore(user->username, user->score); // Update the leaderboard with the current score
}
