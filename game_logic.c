#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "welcome_ui.h"
#include "leader_board.h"  
#include "game_logic.h"  
#include "user_profiles.h"  

void printHangman(int incorrectGuesses) {
    printf(CYAN"  +----+\n");
    printf("  |    |\n");

    if (incorrectGuesses >= 1)
        printf(RED"  O    |\n"RESET);
    else
        printf(CYAN"       |\n"RESET);

    if (incorrectGuesses >= 2)
        printf(CYAN"  |    |\n"RESET);
    else
        printf(CYAN"       |\n"RESET);

    if (incorrectGuesses >= 3)
        printf(CYAN" /|\\   |\n"RESET);
    else
        printf(CYAN"       |\n"RESET);

    if (incorrectGuesses >= 4)
        printf(CYAN" / \\   |\n"RESET);
    else
        printf(CYAN"       |\n"RESET);

    printf(CYAN"       |\n"RESET);
    printf(CYAN" ========\n"RESET);
}


void playGame(User *user, int difficultyLevel) {
    char words[3][20] = {"canteen", "library", "electronic"};
    char hints[3][50] = {"food mood", "please maintain silence", "devices run by circuits"};

    char *word;
    char *hint;

    if (difficultyLevel == 1) { // level is easy
        word = words[0];
        hint = hints[0];
    } else if (difficultyLevel == 2) { // medium
        word = words[1];
        hint = hints[1];
    } else if (difficultyLevel == 3) { // Hard
        word = words[2];
        hint = hints[2];
    } else {
        // run the loop until a valid level is entered
        while (1) {
            printf("\nPlease enter a valid Level (1-3): ");
            scanf("%d", &difficultyLevel);
            if (difficultyLevel >= 1 && difficultyLevel <= 3) {
                break;
            } else {
                printf("Invalid level. Try again.\n");
            }
        }
        // call the playGame again with the valid difficultyLevel to enter values again
        playGame(user, difficultyLevel);
        return; 
    }

    int wordLength = strlen(word);
    char guessedWord[wordLength + 1]; 
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

    while (incorrectGuesses < maxIncorrectGuesses) {
        printf("Enter a letter to guess: ");
        scanf(" %c", &guessedLetter);  
        guessedLetter = tolower(guessedLetter);  // convert the upper input chars to lowercase

        found = 0;
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guessedLetter && guessedWord[i] == '_') {
                guessedWord[i] = guessedLetter;
                found = 1;
            }
        }
        if (!found) {
            incorrectGuesses++;
        }

        printHangman(incorrectGuesses); // display hangman according to lives left

        printf("Word: %s\n", guessedWord);
        printf("Remaining lives: %d\n", maxIncorrectGuesses - incorrectGuesses);

        if (strcmp(word, guessedWord) == 0) {
            printf("Congratulations, %s! You guessed the word correctly.\n", user->username);
            user->score += 10;
            break;
        }
    }

    if (incorrectGuesses == maxIncorrectGuesses) {
        printf(RED"Game Over! \n"RESET);
        printf("The word was: %s\n", word);
    }

    printf(GREEN"Your score: %d\n"RESET, user->score);

    printf("Would you like to:\n1. Show Leaderboard\n2. Exit\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        displayLeaderboard();
    } else {
        printf("Exiting the game...\n");
    }

    updateScore(user->username, user->score); 
}

